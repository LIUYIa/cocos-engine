import { MouseCallback } from 'pal/input';
import { screenAdapter } from 'pal/screen-adapter';
import { EventMouse } from '../../../cocos/input/types';
import { EventTarget } from '../../../cocos/core/event';
import { Vec2 } from '../../../cocos/core/math';
import { InputEventType } from '../../../cocos/input/types/event-enum';

declare const jsb: any;

export class MouseInputSource {
    private _eventTarget: EventTarget = new EventTarget();
    private _preMousePos: Vec2 = new Vec2();
    private _isPressed = false;
    private _windowManager: any;

    private _handleMouseDown: (mouseEvent: jsb.MouseEvent) => void;
    private _handleMouseMove: (mouseEvent: jsb.MouseEvent) => void;
    private _handleMouseUp: (mouseEvent: jsb.MouseEvent) => void;
    private _boundedHandleMouseWheel: (mouseEvent: jsb.MouseWheelEvent) => void;

    constructor () {
        this._handleMouseDown = this._createCallback(InputEventType.MOUSE_DOWN);
        this._handleMouseMove = this._createCallback(InputEventType.MOUSE_MOVE);
        this._handleMouseUp =  this._createCallback(InputEventType.MOUSE_UP);
        this._boundedHandleMouseWheel = this._handleMouseWheel.bind(this);
        this._registerEvent();
        this._windowManager = jsb.ISystemWindowManager.getInstance();
    }

    public dispatchMouseDownEvent (nativeMouseEvent: any) { this._handleMouseDown(nativeMouseEvent); }
    public dispatchMouseMoveEvent (nativeMouseEvent: any) { this._handleMouseMove(nativeMouseEvent); }
    public dispatchMouseUpEvent (nativeMouseEvent: any) { this._handleMouseUp(nativeMouseEvent); }
    public dispatchScrollEvent (nativeMouseEvent: any) { this._boundedHandleMouseWheel(nativeMouseEvent); }

    private _getLocation (event: jsb.MouseEvent): Vec2 {
        const window = this._windowManager.getWindow(event.windowId);
        const windowSize = window.getViewSize();
        const dpr = screenAdapter.devicePixelRatio;
        const x = event.x * dpr;
        const y = windowSize.height - event.y * dpr;
        return new Vec2(x, y);
    }

    private _registerEvent () {
        jsb.onMouseDown = this._handleMouseDown;
        jsb.onMouseMove = this._handleMouseMove;
        jsb.onMouseUp =  this._handleMouseUp;
        jsb.onMouseWheel = this._boundedHandleMouseWheel;
    }

    private _createCallback (eventType: InputEventType) {
        return (mouseEvent: jsb.MouseEvent) => {
            const location = this._getLocation(mouseEvent);
            let button = mouseEvent.button;
            switch (eventType) {
            case InputEventType.MOUSE_DOWN:
                this._isPressed = true;
                break;
            case InputEventType.MOUSE_UP:
                this._isPressed = false;
                break;
            case InputEventType.MOUSE_MOVE:
                if (!this._isPressed) {
                    button = EventMouse.BUTTON_MISSING;
                }
                break;
            default:
                break;
            }

            const eventMouse = new EventMouse(eventType, false, this._preMousePos, mouseEvent.windowId);
            eventMouse.setLocation(location.x, location.y);
            eventMouse.setButton(button);
            eventMouse.movementX = location.x - this._preMousePos.x;
            eventMouse.movementY = this._preMousePos.y - location.y;
            eventMouse.windowId = mouseEvent.windowId;

            // update previous mouse position.
            this._preMousePos.set(location.x, location.y);
            this._eventTarget.emit(eventType, eventMouse);
        };
    }

    private _handleMouseWheel (mouseEvent: jsb.MouseWheelEvent) {
        const eventType = InputEventType.MOUSE_WHEEL;
        const location = this._getLocation(mouseEvent);
        const button = mouseEvent.button;

        const eventMouse = new EventMouse(eventType, false, this._preMousePos);
        eventMouse.setLocation(location.x, location.y);
        eventMouse.setButton(button);
        eventMouse.movementX = location.x - this._preMousePos.x;
        eventMouse.movementY = this._preMousePos.y - location.y;

        const matchStandardFactor = 120;
        eventMouse.setScrollData(mouseEvent.wheelDeltaX * matchStandardFactor, mouseEvent.wheelDeltaY * matchStandardFactor);
        // update previous mouse position.
        this._preMousePos.set(location.x, location.y);
        this._eventTarget.emit(eventType, eventMouse);
    }

    public on (eventType: InputEventType, callback: MouseCallback, target?: any) {
        this._eventTarget.on(eventType, callback, target);
    }
}

// clang-format off

/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.1.0
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

/****************************************************************************
 Copyright (c) 2022 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
****************************************************************************/

#pragma once
#include "bindings/jswrapper/SeApi.h"
#include "bindings/manual/jsb_conversions.h"
#include "2d/renderer/RenderDrawInfo.h"
#include "2d/renderer/UIMeshBuffer.h"
#include "2d/renderer/Batcher2d.h"
#include "2d/renderer/RenderEntity.h"
#include "2d/renderer/UIModelProxy.h"



bool register_all_native2d(se::Object* obj);


JSB_REGISTER_OBJECT_TYPE(cc::MeshBufferLayout);
extern se::Object *__jsb_cc_MeshBufferLayout_proto; // NOLINT
extern se::Class * __jsb_cc_MeshBufferLayout_class; // NOLINT


template<>
bool sevalue_to_native(const se::Value &from, cc::MeshBufferLayout * to, se::Object *ctx);


JSB_REGISTER_OBJECT_TYPE(cc::UIMeshBuffer);
extern se::Object *__jsb_cc_UIMeshBuffer_proto; // NOLINT
extern se::Class * __jsb_cc_UIMeshBuffer_class; // NOLINT


JSB_REGISTER_OBJECT_TYPE(cc::Render2dLayout);
extern se::Object *__jsb_cc_Render2dLayout_proto; // NOLINT
extern se::Class * __jsb_cc_Render2dLayout_class; // NOLINT


template<>
bool sevalue_to_native(const se::Value &from, cc::Render2dLayout * to, se::Object *ctx);


JSB_REGISTER_OBJECT_TYPE(cc::LocalDSBF);
extern se::Object *__jsb_cc_LocalDSBF_proto; // NOLINT
extern se::Class * __jsb_cc_LocalDSBF_class; // NOLINT


template<>
bool sevalue_to_native(const se::Value &from, cc::LocalDSBF * to, se::Object *ctx);


JSB_REGISTER_OBJECT_TYPE(cc::RenderDrawInfo);
extern se::Object *__jsb_cc_RenderDrawInfo_proto; // NOLINT
extern se::Class * __jsb_cc_RenderDrawInfo_class; // NOLINT


JSB_REGISTER_OBJECT_TYPE(cc::EntityAttrLayout);
extern se::Object *__jsb_cc_EntityAttrLayout_proto; // NOLINT
extern se::Class * __jsb_cc_EntityAttrLayout_class; // NOLINT


template<>
bool sevalue_to_native(const se::Value &from, cc::EntityAttrLayout * to, se::Object *ctx);


JSB_REGISTER_OBJECT_TYPE(cc::RenderEntity);
extern se::Object *__jsb_cc_RenderEntity_proto; // NOLINT
extern se::Class * __jsb_cc_RenderEntity_class; // NOLINT


JSB_REGISTER_OBJECT_TYPE(cc::UIModelProxy);
extern se::Object *__jsb_cc_UIModelProxy_proto; // NOLINT
extern se::Class * __jsb_cc_UIModelProxy_class; // NOLINT


JSB_REGISTER_OBJECT_TYPE(cc::Batcher2d);
extern se::Object *__jsb_cc_Batcher2d_proto; // NOLINT
extern se::Class * __jsb_cc_Batcher2d_class; // NOLINT

// clang-format on

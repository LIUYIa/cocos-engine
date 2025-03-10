/****************************************************************************
 Copyright (c) 2017-2022 Xiamen Yaji Software Co., Ltd.

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

#include "jsb_platform.h"

#include "cocos/bindings/jswrapper/SeApi.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#include "cocos/bindings/manual/jsb_global.h"
#include "cocos/platform/FileUtils.h"
#include "cocos/platform/java/jni/JniHelper.h"

#include <regex>

#ifndef JCLS_CANVASIMPL
    #define JCLS_CANVASIMPL "com/cocos/lib/CanvasRenderingContext2DImpl"
#endif

static ccstd::unordered_map<ccstd::string, ccstd::string> gFontFamilyNameMap;

const ccstd::unordered_map<ccstd::string, ccstd::string> &getFontFamilyNameMap() {
    return gFontFamilyNameMap;
}

static bool jsbLoadFont(se::State &s) {
    const auto &args = s.args();
    size_t argc = args.size();
    CC_UNUSED bool ok = true;
    if (argc >= 1) {
        s.rval().setNull();

        ccstd::string originalFamilyName;
        ok &= sevalue_to_native(args[0], &originalFamilyName);
        SE_PRECONDITION2(ok, false, "Error processing argument: originalFamilyName");

        ccstd::string source;
        ok &= sevalue_to_native(args[1], &source);
        SE_PRECONDITION2(ok, false, "Error processing argument: source");

        ccstd::string fontFilePath;
        std::regex re(R"(url\(\s*'\s*(.*?)\s*'\s*\))");
        std::match_results<ccstd::string::const_iterator> results;
        if (std::regex_search(source.cbegin(), source.cend(), results, re)) {
            fontFilePath = results[1].str();
        }

        fontFilePath = cc::FileUtils::getInstance()->fullPathForFilename(fontFilePath);
        if (fontFilePath.empty()) {
            SE_LOGE("Font (%s) doesn't exist!", fontFilePath.c_str());
            return true;
        }

        cc::JniHelper::callStaticVoidMethod(JCLS_CANVASIMPL, "loadTypeface", originalFamilyName, fontFilePath);

        s.rval().setString(originalFamilyName);

        return true;
    }

    SE_REPORT_ERROR("wrong number of arguments: %d, was expecting %d", (int)argc, 1);
    return false;
}
SE_BIND_FUNC(jsbLoadFont)

bool register_platform_bindings(se::Object * /*obj*/) { // NOLINT(readability-identifier-naming)
    __jsbObj->defineFunction("loadFont", _SE(jsbLoadFont));
    return true;
}
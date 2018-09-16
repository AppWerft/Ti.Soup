/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2016 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This is generated, do not edit by hand. **/

#include <jni.h>

#include "Proxy.h"

namespace de {
namespace appwerft {
namespace soup {
	namespace soup {

class ElementProxy : public titanium::Proxy
{
public:
	explicit ElementProxy();

	static void bindProxy(v8::Local<v8::Object>, v8::Local<v8::Context>);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Isolate*);
	static void dispose(v8::Isolate*);

	static jclass javaClass;

private:
	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;

	// Methods -----------------------------------------------------------
	static void getHtml(const v8::FunctionCallbackInfo<v8::Value>&);
	static void hasClassName(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getAttributes(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getText(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getChild(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getSiblingElements(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getChildren(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getAttribute(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getPreviousElementSibling(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getFirstElementSibling(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getOwnText(const v8::FunctionCallbackInfo<v8::Value>&);
	static void toString(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getNextElementSibling(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getLastElementSibling(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getClassNames(const v8::FunctionCallbackInfo<v8::Value>&);

	// Dynamic property accessors ----------------------------------------

};

	} // namespace soup
} // soup
} // appwerft
} // de

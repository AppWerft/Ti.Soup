/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2018 by Appcelerator, Inc. All Rights Reserved.
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

class DocumentProxy : public titanium::Proxy
{
public:
	explicit DocumentProxy();

	static void bindProxy(v8::Local<v8::Object>, v8::Local<v8::Context>);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Isolate*);
	static v8::Local<v8::FunctionTemplate> getProxyTemplate(v8::Local<v8::Context>);
	static void dispose(v8::Isolate*);

	static jclass javaClass;

private:
	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;

	// Methods -----------------------------------------------------------
	static void getElementById(const v8::FunctionCallbackInfo<v8::Value>&);
	static void select(const v8::FunctionCallbackInfo<v8::Value>&);
	static void selectFirst(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getElementsByClass(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getElementsByTag(const v8::FunctionCallbackInfo<v8::Value>&);
	static void toString(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getApiName(const v8::FunctionCallbackInfo<v8::Value>&);
	static void getElementsByAttribute(const v8::FunctionCallbackInfo<v8::Value>&);

	// Dynamic property accessors ----------------------------------------

};

	} // namespace soup
} // soup
} // appwerft
} // de

/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2013 by Appcelerator, Inc. All Rights Reserved.
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
	explicit ElementProxy(jobject javaObject);

	static void bindProxy(v8::Handle<v8::Object> exports);
	static v8::Handle<v8::FunctionTemplate> getProxyTemplate();
	static void dispose();

	static v8::Persistent<v8::FunctionTemplate> proxyTemplate;
	static jclass javaClass;

private:
	// Methods -----------------------------------------------------------
	static v8::Handle<v8::Value> getHtml(const v8::Arguments&);
	static v8::Handle<v8::Value> hasClassName(const v8::Arguments&);
	static v8::Handle<v8::Value> getAttributes(const v8::Arguments&);
	static v8::Handle<v8::Value> getText(const v8::Arguments&);
	static v8::Handle<v8::Value> getChild(const v8::Arguments&);
	static v8::Handle<v8::Value> getSiblingElements(const v8::Arguments&);
	static v8::Handle<v8::Value> getChildren(const v8::Arguments&);
	static v8::Handle<v8::Value> getAttribute(const v8::Arguments&);
	static v8::Handle<v8::Value> getPreviousElementSibling(const v8::Arguments&);
	static v8::Handle<v8::Value> getFirstElementSibling(const v8::Arguments&);
	static v8::Handle<v8::Value> getOwnText(const v8::Arguments&);
	static v8::Handle<v8::Value> toString(const v8::Arguments&);
	static v8::Handle<v8::Value> getNextElementSibling(const v8::Arguments&);
	static v8::Handle<v8::Value> getLastElementSibling(const v8::Arguments&);
	static v8::Handle<v8::Value> getClassNames(const v8::Arguments&);

	// Dynamic property accessors ----------------------------------------

};

			} // namespace soup
		} // soup
		} // appwerft
		} // de

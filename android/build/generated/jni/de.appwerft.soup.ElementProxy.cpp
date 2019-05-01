/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011-2018 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 */

/** This code is generated, do not edit by hand. **/

#include "de.appwerft.soup.ElementProxy.h"

#include "AndroidUtil.h"
#include "JNIUtil.h"
#include "JSException.h"
#include "TypeConverter.h"
#include "V8Util.h"


#include "org.appcelerator.kroll.KrollProxy.h"

#define TAG "ElementProxy"

using namespace v8;

namespace de {
namespace appwerft {
namespace soup {
	namespace soup {


Persistent<FunctionTemplate> ElementProxy::proxyTemplate;
jclass ElementProxy::javaClass = NULL;

ElementProxy::ElementProxy() : titanium::Proxy()
{
}

void ElementProxy::bindProxy(Local<Object> exports, Local<Context> context)
{
	Isolate* isolate = context->GetIsolate();

	Local<FunctionTemplate> pt = getProxyTemplate(isolate);

	v8::TryCatch tryCatch(isolate);
	Local<Function> constructor;
	MaybeLocal<Function> maybeConstructor = pt->GetFunction(context);
	if (!maybeConstructor.ToLocal(&constructor)) {
		titanium::V8Util::fatalException(isolate, tryCatch);
		return;
	}

	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Element"); // use symbol over string for efficiency
	exports->Set(context, nameSymbol, constructor);
}

void ElementProxy::dispose(Isolate* isolate)
{
	LOGD(TAG, "dispose()");
	if (!proxyTemplate.IsEmpty()) {
		proxyTemplate.Reset();
	}

	titanium::KrollProxy::dispose(isolate);
}

Local<FunctionTemplate> ElementProxy::getProxyTemplate(v8::Isolate* isolate)
{
	Local<Context> context = isolate->GetCurrentContext();
	if (!proxyTemplate.IsEmpty()) {
		return proxyTemplate.Get(isolate);
	}

	LOGD(TAG, "ElementProxy::getProxyTemplate()");

	javaClass = titanium::JNIUtil::findClass("de/appwerft/soup/ElementProxy");
	EscapableHandleScope scope(isolate);

	// use symbol over string for efficiency
	Local<String> nameSymbol = NEW_SYMBOL(isolate, "Element");

	Local<FunctionTemplate> t = titanium::Proxy::inheritProxyTemplate(
		isolate,
		titanium::KrollProxy::getProxyTemplate(isolate),
		javaClass,
		nameSymbol);

	proxyTemplate.Reset(isolate, t);
	t->Set(titanium::Proxy::inheritSymbol.Get(isolate), FunctionTemplate::New(isolate, titanium::Proxy::inherit<ElementProxy>));

	// Method bindings --------------------------------------------------------
	titanium::SetProtoMethod(isolate, t, "getHtml", ElementProxy::getHtml);
	titanium::SetProtoMethod(isolate, t, "hasClassName", ElementProxy::hasClassName);
	titanium::SetProtoMethod(isolate, t, "getAttributes", ElementProxy::getAttributes);
	titanium::SetProtoMethod(isolate, t, "select", ElementProxy::select);
	titanium::SetProtoMethod(isolate, t, "getText", ElementProxy::getText);
	titanium::SetProtoMethod(isolate, t, "selectFirst", ElementProxy::selectFirst);
	titanium::SetProtoMethod(isolate, t, "getChild", ElementProxy::getChild);
	titanium::SetProtoMethod(isolate, t, "getSiblingElements", ElementProxy::getSiblingElements);
	titanium::SetProtoMethod(isolate, t, "getLastChild", ElementProxy::getLastChild);
	titanium::SetProtoMethod(isolate, t, "getChildren", ElementProxy::getChildren);
	titanium::SetProtoMethod(isolate, t, "getAttribute", ElementProxy::getAttribute);
	titanium::SetProtoMethod(isolate, t, "getPreviousElementSibling", ElementProxy::getPreviousElementSibling);
	titanium::SetProtoMethod(isolate, t, "getElementsByClass", ElementProxy::getElementsByClass);
	titanium::SetProtoMethod(isolate, t, "getElementsByTag", ElementProxy::getElementsByTag);
	titanium::SetProtoMethod(isolate, t, "getFirstElementSibling", ElementProxy::getFirstElementSibling);
	titanium::SetProtoMethod(isolate, t, "getFirstChild", ElementProxy::getFirstChild);
	titanium::SetProtoMethod(isolate, t, "getOwnText", ElementProxy::getOwnText);
	titanium::SetProtoMethod(isolate, t, "toString", ElementProxy::toString);
	titanium::SetProtoMethod(isolate, t, "getApiName", ElementProxy::getApiName);
	titanium::SetProtoMethod(isolate, t, "getNextElementSibling", ElementProxy::getNextElementSibling);
	titanium::SetProtoMethod(isolate, t, "getLastElementSibling", ElementProxy::getLastElementSibling);
	titanium::SetProtoMethod(isolate, t, "getClassNames", ElementProxy::getClassNames);

	Local<ObjectTemplate> prototypeTemplate = t->PrototypeTemplate();
	Local<ObjectTemplate> instanceTemplate = t->InstanceTemplate();

	// Delegate indexed property get and set to the Java proxy.
	instanceTemplate->SetIndexedPropertyHandler(titanium::Proxy::getIndexedProperty,
		titanium::Proxy::setIndexedProperty);

	// Constants --------------------------------------------------------------

	// Dynamic properties -----------------------------------------------------
	instanceTemplate->SetAccessor(
		NEW_SYMBOL(isolate, "apiName"),
		ElementProxy::getter_apiName,
		titanium::Proxy::onPropertyChanged,
		Local<Value>(),
		DEFAULT,
		static_cast<v8::PropertyAttribute>(v8::ReadOnly | v8::DontDelete)
	);

	// Accessors --------------------------------------------------------------

	return scope.Escape(t);
}

Local<FunctionTemplate> ElementProxy::getProxyTemplate(v8::Local<v8::Context> context)
{
	return getProxyTemplate(context->GetIsolate());
}

// Methods --------------------------------------------------------------------
void ElementProxy::getHtml(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getHtml()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getHtml", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getHtml' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::hasClassName(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "hasClassName()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "hasClassName", "(Ljava/lang/String;)Z");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'hasClassName' with signature '(Ljava/lang/String;)Z'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "hasClassName: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jboolean jResult = (jboolean)env->CallBooleanMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}


	Local<Boolean> v8Result = titanium::TypeConverter::javaBooleanToJsBoolean(isolate, env, jResult);



	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getAttributes(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getAttributes()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getAttributes", "()Lorg/appcelerator/kroll/KrollDict;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getAttributes' with signature '()Lorg/appcelerator/kroll/KrollDict;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::select(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "select()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "select", "(Ljava/lang/String;)[Ljava/lang/Object;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'select' with signature '(Ljava/lang/String;)[Ljava/lang/Object;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "select: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobjectArray jResult = (jobjectArray)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Array> v8Result = titanium::TypeConverter::javaArrayToJsArray(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getText(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getText()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getText", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getText' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::selectFirst(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "selectFirst()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "selectFirst", "(Ljava/lang/String;)Lde/appwerft/soup/ElementProxy;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'selectFirst' with signature '(Ljava/lang/String;)Lde/appwerft/soup/ElementProxy;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "selectFirst: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getChild(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getChild()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getChild", "(I)Lde/appwerft/soup/ElementProxy;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getChild' with signature '(I)Lde/appwerft/soup/ElementProxy;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "getChild: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
		if ((titanium::V8Util::isNaN(isolate, args[0]) && !args[0]->IsUndefined()) || args[0]->ToString(context).FromMaybe(String::Empty(isolate))->Length() == 0) {
			const char *error = "Invalid value, expected type Number.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		}
		if (!args[0]->IsNull()) {
		MaybeLocal<Number> arg_0 = args[0]->ToNumber(context);
		if (arg_0.IsEmpty()) {
			const char *error = "Invalid argument at index 0, expected type Number and failed to coerce.";
			LOGE(TAG, error);
			titanium::JSException::Error(isolate, error);
			return;
		} else {
			jArguments[0].i =
				titanium::TypeConverter::jsNumberToJavaInt(
					env, arg_0.ToLocalChecked());
		}
	} else {
		jArguments[0].i = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getSiblingElements(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getSiblingElements()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getSiblingElements", "()[Ljava/lang/Object;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getSiblingElements' with signature '()[Ljava/lang/Object;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobjectArray jResult = (jobjectArray)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Array> v8Result = titanium::TypeConverter::javaArrayToJsArray(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getLastChild(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getLastChild()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getLastChild", "()Lde/appwerft/soup/ElementProxy;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getLastChild' with signature '()Lde/appwerft/soup/ElementProxy;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getChildren(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getChildren()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getChildren", "()[Ljava/lang/Object;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getChildren' with signature '()[Ljava/lang/Object;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobjectArray jResult = (jobjectArray)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Array> v8Result = titanium::TypeConverter::javaArrayToJsArray(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getAttribute(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getAttribute()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getAttribute", "(Ljava/lang/String;)Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getAttribute' with signature '(Ljava/lang/String;)Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "getAttribute: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getPreviousElementSibling(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getPreviousElementSibling()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getPreviousElementSibling", "()Lde/appwerft/soup/ElementProxy;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getPreviousElementSibling' with signature '()Lde/appwerft/soup/ElementProxy;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getElementsByClass(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getElementsByClass()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getElementsByClass", "(Ljava/lang/String;)[Ljava/lang/Object;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getElementsByClass' with signature '(Ljava/lang/String;)[Ljava/lang/Object;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "getElementsByClass: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobjectArray jResult = (jobjectArray)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Array> v8Result = titanium::TypeConverter::javaArrayToJsArray(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getElementsByTag(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getElementsByTag()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getElementsByTag", "(Ljava/lang/String;)[Ljava/lang/Object;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getElementsByTag' with signature '(Ljava/lang/String;)[Ljava/lang/Object;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	if (args.Length() < 1) {
		char errorStringBuffer[100];
		sprintf(errorStringBuffer, "getElementsByTag: Invalid number of arguments. Expected 1 but got %d", args.Length());
		titanium::JSException::Error(isolate, errorStringBuffer);
		return;
	}

	jvalue jArguments[1];




	
	if (!args[0]->IsNull()) {
		Local<Value> arg_0 = args[0];
		jArguments[0].l =
			titanium::TypeConverter::jsValueToJavaString(
				isolate,
				env, arg_0);
	} else {
		jArguments[0].l = NULL;
	}


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobjectArray jResult = (jobjectArray)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



				env->DeleteLocalRef(jArguments[0].l);


	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Array> v8Result = titanium::TypeConverter::javaArrayToJsArray(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getFirstElementSibling(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getFirstElementSibling()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getFirstElementSibling", "()Lde/appwerft/soup/ElementProxy;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getFirstElementSibling' with signature '()Lde/appwerft/soup/ElementProxy;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getFirstChild(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getFirstChild()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getFirstChild", "()Lde/appwerft/soup/ElementProxy;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getFirstChild' with signature '()Lde/appwerft/soup/ElementProxy;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getOwnText(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getOwnText()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getOwnText", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getOwnText' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::toString(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "toString()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "toString", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'toString' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getApiName(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getApiName()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getApiName", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getApiName' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	LOGW(TAG, "Automatic getter methods for properties are deprecated in SDK 8.0.0 and will be removed in SDK 9.0.0. Please access the property in standard JS style: obj.apiName; or obj['apiName'];");

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getNextElementSibling(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getNextElementSibling()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getNextElementSibling", "()Lde/appwerft/soup/ElementProxy;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getNextElementSibling' with signature '()Lde/appwerft/soup/ElementProxy;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getLastElementSibling(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getLastElementSibling()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getLastElementSibling", "()Lde/appwerft/soup/ElementProxy;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getLastElementSibling' with signature '()Lde/appwerft/soup/ElementProxy;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobject jResult = (jobject)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaObjectToJsValue(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}
void ElementProxy::getClassNames(const FunctionCallbackInfo<Value>& args)
{
	LOGD(TAG, "getClassNames()");
	Isolate* isolate = args.GetIsolate();
	Local<Context> context = isolate->GetCurrentContext();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getClassNames", "()[Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getClassNames' with signature '()[Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;


	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jobjectArray jResult = (jobjectArray)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Array> v8Result = titanium::TypeConverter::javaArrayToJsArray(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}

// Dynamic property accessors -------------------------------------------------

void ElementProxy::getter_apiName(Local<Name> property, const PropertyCallbackInfo<Value>& args)
{
	Isolate* isolate = args.GetIsolate();
	HandleScope scope(isolate);

	JNIEnv *env = titanium::JNIScope::getEnv();
	if (!env) {
		titanium::JSException::GetJNIEnvironmentError(isolate);
		return;
	}

	Local<Context> context = isolate->GetCurrentContext();
	static jmethodID methodID = NULL;
	if (!methodID) {
		methodID = env->GetMethodID(ElementProxy::javaClass, "getApiName", "()Ljava/lang/String;");
		if (!methodID) {
			const char *error = "Couldn't find proxy method 'getApiName' with signature '()Ljava/lang/String;'";
			LOGE(TAG, error);
				titanium::JSException::Error(isolate, error);
				return;
		}
	}

	Local<Object> holder = args.Holder();
	if (!JavaObject::isJavaObject(holder)) {
		holder = holder->FindInstanceInPrototypeChain(getProxyTemplate(isolate));
	}
	if (holder.IsEmpty() || holder->IsNull()) {
		LOGE(TAG, "Couldn't obtain argument holder");
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	titanium::Proxy* proxy = NativeObject::Unwrap<titanium::Proxy>(holder);
	if (!proxy) {
		args.GetReturnValue().Set(Undefined(isolate));
		return;
	}

	jvalue* jArguments = 0;

	jobject javaProxy = proxy->getJavaObject();
	if (javaProxy == NULL) {
		args.GetReturnValue().Set(v8::Undefined(isolate));
		return;
	}
	jstring jResult = (jstring)env->CallObjectMethodA(javaProxy, methodID, jArguments);



	proxy->unreferenceJavaObject(javaProxy);



	if (env->ExceptionCheck()) {
		Local<Value> jsException = titanium::JSException::fromJavaException(isolate);
		env->ExceptionClear();
		return;
	}

	if (jResult == NULL) {
		args.GetReturnValue().Set(Null(isolate));
		return;
	}

	Local<Value> v8Result = titanium::TypeConverter::javaStringToJsString(isolate, env, jResult);

	env->DeleteLocalRef(jResult);


	args.GetReturnValue().Set(v8Result);

}




	} // namespace soup
} // soup
} // appwerft
} // de

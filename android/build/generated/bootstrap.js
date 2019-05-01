/**
 * Appcelerator Titanium Mobile
 * Copyright (c) 2011 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 * Warning: This file is GENERATED, and should not be modified
 */
var bootstrap = kroll.NativeModule.require("bootstrap"),
	invoker = kroll.NativeModule.require("invoker"),
	Titanium = kroll.binding("Titanium").Titanium;

function moduleBootstrap(moduleBinding) {
	function lazyGet(object, binding, name, namespace) {
		return bootstrap.lazyGet(object, binding,
			name, namespace, moduleBinding.getBinding);
	}

	var module = moduleBinding.getBinding("de.appwerft.soup.SoupModule")["Soup"];
	var invocationAPIs = module.invocationAPIs = [];
	module.apiName = "Soup";

	function addInvocationAPI(module, moduleNamespace, namespace, api) {
		invocationAPIs.push({ namespace: namespace, api: api });
	}

	addInvocationAPI(module, "Soup", "Soup", "createDocument");addInvocationAPI(module, "Soup", "Soup", "createElement");addInvocationAPI(module, "Soup", "Soup", "createJSONObject");
		if (!("__propertiesDefined__" in module)) {Object.defineProperties(module, {
"JSONObject": {
get: function() {
var JSONObject =  lazyGet(this, "de.appwerft.soup.JSONObjectProxy", "JSONObject", "JSONObject");
return JSONObject;
},
configurable: true
},
"Element": {
get: function() {
var Element =  lazyGet(this, "de.appwerft.soup.ElementProxy", "Element", "Element");
return Element;
},
configurable: true
},
"Document": {
get: function() {
var Document =  lazyGet(this, "de.appwerft.soup.DocumentProxy", "Document", "Document");
return Document;
},
configurable: true
},

});
module.constructor.prototype.createDocument = function() {
return new module["Document"](arguments);
}
module.constructor.prototype.createElement = function() {
return new module["Element"](arguments);
}
module.constructor.prototype.createJSONObject = function() {
return new module["JSONObject"](arguments);
}
}
module.__propertiesDefined__ = true;
return module;

}
exports.bootstrap = moduleBootstrap;

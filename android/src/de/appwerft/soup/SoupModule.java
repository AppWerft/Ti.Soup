/**
 * This file was auto-generated by the Titanium Module SDK helper for Android
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2010 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 */
package de.appwerft.soup;

import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.common.Log;
import org.appcelerator.titanium.TiApplication;

import android.app.Activity;

@Kroll.module(name = "Soup", id = "de.appwerft.soup")
public class SoupModule extends KrollModule {
	public static String rootActivityClassName;
	public static String LCAT = "Soup";

	public SoupModule() {
		super();

	}

	@Kroll.onAppCreate
	public static void onAppCreate(TiApplication app) {

	}

	@Kroll.method
	public String getApiName() {
		return "SoupModule";
	}

	@Override
	public void onStart(Activity activity) {
		// This method is called when the module is loaded and the root context
		// is started
		rootActivityClassName = TiApplication.getInstance()
				.getApplicationContext().getPackageName()
				+ "."
				+ TiApplication.getAppRootOrCurrentActivity().getClass()
						.getSimpleName();
		Log.d(LCAT, "onStart rootActivityClassName = " + rootActivityClassName);

		super.onStart(activity);
	}
}

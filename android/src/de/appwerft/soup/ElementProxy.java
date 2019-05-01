/**
 * This file was auto-generated by the Titanium Module SDK helper for Android
 * Appcelerator Titanium Mobile
 * Copyright (c) 2009-2010 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License
 * Please see the LICENSE included with this distribution for details.
 *
 */
package de.appwerft.soup;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.annotations.Kroll;
import org.jsoup.nodes.Attribute;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

@Kroll.proxy(creatableInModule = SoupModule.class)
public class ElementProxy extends KrollProxy {
	public Element elem;

	public ElementProxy(Element e) {
		super();
		elem = e;
	}

	@Kroll.method
	public KrollDict getAttributes() {
		KrollDict kd = new KrollDict();
		for (Attribute a : elem.attributes()) {
			kd.put(a.getKey(), a.getValue());
		}
		kd.put("text", elem.text());
		return kd;
	}

	@Kroll.method
	public String getAttribute(String attr) {
		return elem.attr(attr);
	}

	@Kroll.method
	public String getText() {
		return elem.text();
	}

	@Kroll.method
	public String getOwnText() {
		return elem.ownText();
	}

	@Kroll.method
	public String getHtml() {
		return elem.html();
	}

	@Kroll.method
	public String toString() {
		return elem.toString();
	}

	@Kroll.method
	public Object[] getChildren() {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		Elements elems = elem.children();
		for (Element elem : elems) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();

	}

	@Kroll.method
	public Object[] select(String css) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		Elements elems = elem.select(css);
		for (Element elem : elems) {
			list.add(new ElementProxy(elem));
		}
		return (elems.isEmpty()) ? null : list.toArray();

	}

	@Kroll.method
	public ElementProxy selectFirst(String filter) {
		Elements elems = elem.select(filter);
		return (elems.isEmpty()) ? null : new ElementProxy(elems.get(0));

	}

	@Kroll.method
	Object[] getElementsByClass(String className) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		Elements elems = elem.getElementsByClass(className);
		for (Element elem : elems) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}

	@Kroll.method
	Object[] getElementsByTag(String tagName) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		Elements elems = elem.getElementsByTag(tagName);
		for (Element elem : elems) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}

	@Kroll.method
	public ElementProxy getChild(int ndx) {
		Element element = elem.child(ndx);
		return new ElementProxy(element);
	}

	@Kroll.method
	public ElementProxy getFirstChild() {
		Element element = elem.child(0);
		return new ElementProxy(element);
	}

	@Kroll.method
	public ElementProxy getLastChild() {
		int ndx = elem.childNodeSize() - 1;
		Element element = elem.child(ndx);
		return new ElementProxy(element);
	}

	@Kroll.method
	public Object[] getSiblingElements() {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		for (Element elem : elem.siblingElements()) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}

	@Kroll.method
	public ElementProxy getFirstElementSibling() {
		return new ElementProxy(elem.firstElementSibling());
	}

	@Kroll.method
	public ElementProxy getLastElementSibling() {
		return new ElementProxy(elem.lastElementSibling());
	}

	@Kroll.method
	public ElementProxy getNextElementSibling() {
		return new ElementProxy(elem.nextElementSibling());
	}

	@Kroll.method
	public ElementProxy getPreviousElementSibling() {
		return new ElementProxy(elem.previousElementSibling());
	}

	@Kroll.method
	public String[] getClassNames() {
		String[] names = elem.className().split(" ");
		return names;
	}

	@Kroll.method
	public boolean hasClassName(String needle) {
		String[] names = elem.className().split(" ");
		return Arrays.asList(names).contains(needle);
	}

	@Kroll.method
	@Kroll.getProperty
	public String getApiName() {
		return "de.appwerft.soup.Element";
	}
}   
    
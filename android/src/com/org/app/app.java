package com.org.app;

import com.org.html2json.Html2json;

public class app {

	public static void main(String[] args) {
		String url = "https://en.wikipedia.org/wiki/Main_Page";
		System.out.println(Html2json.getJSON(url));		
	}
}

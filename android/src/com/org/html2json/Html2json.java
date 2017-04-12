package com.org.html2json;

import com.org.httprequest.HTTPReq;
import com.org.jsengine.JSEngine;

import java.util.HashMap;
import java.util.Map;

public class Html2json {
	public Html2json() {
	}

	private static boolean ENABLE_JAVASCRIPT = false;

	public static String special_sanitizer(String html) {
		html = html.replaceAll("<g:plusone>(?:.+?)?<\\/g:plusone>", "");
		html = html.replaceAll("\"title", "\" title");
		return html;
	}

	public static String sanitize_html(String html) {
		html = html.replaceAll("(?:<!.+?>)", ""); // Remove Doctype and comments

		html = html.replaceAll("(?<!\\\\)\"", "\\\\\"");
		if (!ENABLE_JAVASCRIPT)
			html = html.replaceAll("<script(?:.+?)<\\/script>", "");
		html = special_sanitizer(html);
		html = "<div id='html_wrap'>" + html + "</div>";

		return html;
	}

	public static String getJSON(final String url) {
		// Scripts required for the task:
		String[] scripts = { "html2json.js", "htmlparser.js", "main.js",
				"jumpcall.js" };

		// Parameters to be passed to JS engine:
		@SuppressWarnings("serial")
		Map<String, Object> script_params = new HashMap<String, Object>() {
			{
				put("html",
						sanitize_html(new HTTPReq(false).send(
								HTTPReq.GET_METHOD, url, null).get(1)));
			}
		};

		// Return the JSON in string form:
		return (String) ((String[]) new JSEngine(scripts, script_params).run())[0];
	}
}

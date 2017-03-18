package de.appwerft.soup;

import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollFunction;
import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.common.Log;
import org.appcelerator.titanium.TiC;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;

import android.os.AsyncTask;

@Kroll.proxy(creatableInModule = SoupModule.class)
public class HTMLSoupProxy extends KrollProxy {

	private static final String LCAT = "Soup";
	private Document doc;
	private KrollFunction onLoad;
	private KrollFunction onError;
	private String url;

	private final class SoupRequestHandler extends
			AsyncTask<Void, Void, KrollDict> {
		@Override
		protected KrollDict doInBackground(Void[] arg0) {
			KrollDict resultDict = new KrollDict();
			try {
				doc = Jsoup.connect(url).ignoreContentType(false).get();
			} catch (IOException e) {
				e.printStackTrace();
				if (onError != null)
					onError.call(getKrollObject(), resultDict);
			}
			return resultDict;
		}

		protected void onPostExecute(KrollDict resultDict) {
			Log.d(LCAT, ">>>> onPostExecute");
			if (onLoad != null) {
				resultDict.put("charset", doc.charset().name());
				resultDict.put("location", doc.location());
				resultDict.put("length", doc.toString().length());
				onLoad.call(getKrollObject(), resultDict);
			} else
				Log.w(LCAT, "onload is missing");
		}
	}

	public HTMLSoupProxy() {
		super();
	}

	@Override
	public void handleCreationDict(KrollDict opts) {
		super.handleCreationDict(opts);
		Log.d(LCAT, ">>>>>>handleCreationArgs");
		if (opts.containsKeyAndNotNull(TiC.PROPERTY_URL)) {
			url = opts.getString(TiC.PROPERTY_URL);
		}
		if (opts.containsKeyAndNotNull(TiC.PROPERTY_HTML)) {
			doc = new Document(opts.getString(TiC.PROPERTY_HTML));
		}
		if (opts.containsKeyAndNotNull(TiC.PROPERTY_ONLOAD)) {
			Log.d(LCAT, ">>>>>>onLoad imported");
			onLoad = (KrollFunction) opts.get(TiC.PROPERTY_ONLOAD);
		}
		if (opts.containsKeyAndNotNull(TiC.PROPERTY_ONERROR)) {
			onError = (KrollFunction) opts.get(TiC.PROPERTY_ONERROR);
		}

		try {
			@SuppressWarnings("unused")
			URL dummy = new URL(url);
			AsyncTask<Void, Void, KrollDict> doRequest = new SoupRequestHandler();
			doRequest.execute();
		} catch (MalformedURLException e) {
			Log.d(LCAT, "URL=" + url);
			e.printStackTrace();

			if (onError != null) {
				onError.call(getKrollObject(), new KrollDict());
			}
		}
	}

	@Kroll.method
	public ElementProxy getElementById(final String id) {
		ElementProxy elem = new ElementProxy(doc.getElementById(id));
		return elem;
	}

	@Kroll.method
	public Object[] getElementsByClass(final String clazz) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		for (Element elem : doc.getElementsByClass(clazz)) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}

	@Kroll.method
	public Object[] select(final String filter) {
		Log.d(LCAT, "SELECT='" + filter + "'");
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		Elements elems = doc.select(filter);
		for (Element elem : elems) {
			Log.d(LCAT, elem.toString());
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}

	@Kroll.method
	public Object[] getElementsByTag(final String clazz) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		for (Element elem : doc.getElementsByClass(clazz)) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}

	@Kroll.method
	public Object[] getElementsByAttribute(final String clazz) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		for (Element elem : doc.getElementsByAttribute(clazz)) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}
}
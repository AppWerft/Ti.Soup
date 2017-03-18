package de.appwerft.soup;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollFunction;
import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.titanium.TiC;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

import android.os.AsyncTask;

@Kroll.proxy(creatableInModule = SoupModule.class)
public class SoupProxy extends KrollProxy {

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
			if (onLoad != null)
				onLoad.call(getKrollObject(), resultDict);
		}
	}

	// Constructor
	public SoupProxy() {
		super();
	}

	@Override
	public void handleCreationArgs(KrollModule module, Object[] args) {
		if (args.length == 1 && args[0] instanceof KrollDict) {
			KrollDict opts = (KrollDict) args[0];
			if (opts.containsKeyAndNotNull(TiC.PROPERTY_URL)) {
				url = opts.getString(TiC.PROPERTY_URL);
			}
			if (opts.containsKeyAndNotNull(TiC.PROPERTY_HTML)) {
				doc = new Document(opts.getString(TiC.PROPERTY_HTML));
			}
			if (opts.containsKeyAndNotNull(TiC.PROPERTY_ONLOAD)) {
				onLoad = (KrollFunction) opts.get(TiC.PROPERTY_ONLOAD);
			}
			if (opts.containsKeyAndNotNull(TiC.PROPERTY_ONERROR)) {
				onLoad = (KrollFunction) opts.get(TiC.PROPERTY_ONERROR);
			}
		} else if (args.length == 2 && args[0] instanceof String
				&& args[1] instanceof KrollFunction) {
			url = (String) args[0];
			onLoad = (KrollFunction) args[1];
		} else if (args.length == 3 && args[0] instanceof String
				&& args[1] instanceof KrollFunction
				&& args[2] instanceof KrollFunction) {
			url = (String) args[0];
			onLoad = (KrollFunction) args[1];
			onError = (KrollFunction) args[2];
		}
		AsyncTask<Void, Void, KrollDict> doRequest = new SoupRequestHandler();
		doRequest.execute();
	}

	public ElementProxy getElementById(final String id) {
		ElementProxy elem = new ElementProxy(doc.getElementById(id));
		return elem;
	}

	public Object[] getElementsByClass(final String clazz) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		for (Element elem : doc.getElementsByClass(clazz)) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}

	public Object[] select(final String filter) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		for (Element elem : doc.select(filter)) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}

	public Object[] getElementsByTag(final String clazz) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		for (Element elem : doc.getElementsByClass(clazz)) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}

	public Object[] getElementsByAttribute(final String clazz) {
		List<ElementProxy> list = new ArrayList<ElementProxy>();
		for (Element elem : doc.getElementsByAttribute(clazz)) {
			list.add(new ElementProxy(elem));
		}
		return list.toArray();
	}
}
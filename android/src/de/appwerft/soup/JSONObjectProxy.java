package de.appwerft.soup;

import java.net.MalformedURLException;
import java.net.URL;

import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollFunction;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.common.Log;
import org.appcelerator.titanium.TiC;
import org.json.JSONException;
import org.json.JSONObject;
import org.jsoup.nodes.Document;

import android.os.AsyncTask;

import com.org.html2json.Html2json;

@Kroll.proxy(creatableInModule = SoupModule.class)
public class JSONObjectProxy extends KrollProxy {

	private static final String LCAT = SoupModule.LCAT;
	private KrollFunction onLoad;
	private KrollFunction onError;
	private String url;

	private final class JSONRequestHandler extends
			AsyncTask<Void, Void, JSONObject> {
		@Override
		protected JSONObject doInBackground(Void... empty) {
			try {
				Log.d(LCAT, url);
				return new JSONObject(Html2json.getJSON(url));
			} catch (JSONException e) {
				e.printStackTrace();
			}
			return new JSONObject();
		}

		protected void onPostExecute(JSONObject result) {
			if (onLoad != null) {
				try {
					onLoad.call(getKrollObject(), new KrollDict(result));
				} catch (JSONException e) {
					e.printStackTrace();
				}

			} else
				Log.w(LCAT, "onload is missing");
		}
	}

	public JSONObjectProxy() {
		super();
	}

	@Override
	public void handleCreationDict(KrollDict opts) {
		super.handleCreationDict(opts);
		if (opts.containsKeyAndNotNull(TiC.PROPERTY_URL)) {
			try {
				url = opts.getString(TiC.PROPERTY_URL);
				@SuppressWarnings("unused")
				URL dummy = new URL(url);
				AsyncTask<Void, Void, JSONObject> doRequest = new JSONRequestHandler();
				doRequest.execute();
			} catch (MalformedURLException e) {
				KrollDict kd = new KrollDict();
				kd.put("message", e.getMessage());
				kd.put("url", url);
				if (onError != null) {
					onError.call(getKrollObject(), kd);
				}
			}
		}

		if (opts.containsKeyAndNotNull(TiC.PROPERTY_ONLOAD)) {
			onLoad = (KrollFunction) opts.get(TiC.PROPERTY_ONLOAD);
		}
		if (opts.containsKeyAndNotNull(TiC.PROPERTY_ONERROR)) {
			onError = (KrollFunction) opts.get(TiC.PROPERTY_ONERROR);
		}

	}

}
package com.org.httprequest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.ArrayList;
import java.util.Map;

public class HTTPReq{
	public static String GET_METHOD = "GET";
	public static String POST_METHOD = "POST"; 
	private String USER_AGENT = "Mozilla/5.0";
	private boolean using_headers = false;
	
	public HTTPReq(boolean using_headers){this.using_headers = using_headers;}	
	
	public ArrayList<String> send(String method, String url, Map<String, String> headers){
		ArrayList<String> result = new ArrayList<String>();
		
		try {
			HttpURLConnection conn = (HttpURLConnection) new URL(url).openConnection(); 
			conn.setRequestMethod(method);
			
			// Default headers:
			conn.setRequestProperty("User-Agent", USER_AGENT);
			
			// Custom headers:			
			if(using_headers && headers != null)
				for(String header: headers.keySet())
					conn.setRequestProperty(header, headers.get(header));
			
			// Always first:
			result.add(Integer.toString(conn.getResponseCode()));
			
			BufferedReader input = new BufferedReader(new InputStreamReader(conn.getInputStream()));
			
			String in_line;
			StringBuffer in_buffer = new StringBuffer();
			
			while((in_line = input.readLine()) !=null)
				in_buffer.append(in_line);
			
			input.close();
			
			result.add(in_buffer.toString());
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return result;
	}
}
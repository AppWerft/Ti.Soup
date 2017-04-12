package com.org.jsengine;

import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;

import org.json.JSONArray;

public class JSEngine{
	private ArrayList<String> scripts_path;
	private Map<String, Object> scripts_params;
	private FileReader script_reader;
	private ScriptEngine script_engine;
	private boolean using_params = false;
	
	public JSEngine(String script_path){
		scripts_path = new ArrayList<String>();
		scripts_path.add(script_path);
	}
	
	public JSEngine(String script_path, Map<String, Object> scripts_params){
		scripts_path = new ArrayList<String>();
		scripts_path.add(script_path);
		this.scripts_params = scripts_params;
		using_params = true;
	}
	
	public JSEngine(String[] scripts_path){
		this.scripts_path = new ArrayList<String>(Arrays.asList(scripts_path));
	}
	
	public JSEngine(String[] scripts_path, Map<String, Object> scripts_params){
		this.scripts_path = new ArrayList<String>(Arrays.asList(scripts_path));
		this.scripts_params = scripts_params;
		using_params = true;
	}
	
	public String get_nth_key(Map<String, Object> hash , int index){
		int i = 0;
		for(String key: hash.keySet()) if(i==index) return key; else i++;
		return "";
	}
	
	public static String java_array_to_json(Object [] arr){
		return new JSONArray(Arrays.asList(arr)).toString();
	}
	
	public String value_type_resolve(Object obj){
		String return_value  = "";
		if(obj.getClass().equals(String.class))
			return_value = "\"" + (String) obj+ "\"";
		else if(obj.getClass().equals(Integer.class))
			return_value =  Integer.toString(((int)obj));
		else if(obj.getClass().equals(Object[].class))
			return_value=java_array_to_json((Object[]) obj);
		
		return return_value;	
	}
	
	public Object run(){
		Object res = null;
		
		script_engine = new ScriptEngineManager().getEngineByName("JavaScript");
		
		try {
			
			if(using_params){
				String strbuild = "";
				int param_count = scripts_params.size();
				
				script_engine.put("param", "{}");
				for(int i=0;i<param_count;i++){
					
					String key = get_nth_key(scripts_params, i);
					strbuild += "'"+key+"': "+value_type_resolve(scripts_params.get(key));
					if(i<param_count-1) strbuild+=", ";
					
				}
				script_engine.eval("var param = {"+strbuild+"};");
			}
		
			for(int i=0; i<scripts_path.size(); i++){
				script_reader = new FileReader(scripts_path.get(i));
				script_engine.eval(script_reader);
				script_reader.close();
			}
			
			res = script_engine.get("out_buffer");
		} catch (ScriptException | IOException e) {
			e.printStackTrace();
		}
		
		return res;
	}
}
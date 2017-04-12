# Ti.Soup
<img src="http://cdn1.javacodeexamples.com/wp-content/uploads/Jsoup-300x200.png" width=200 />
Titanium module for parsing remote HTML. It is Titanium version of Jsoup.

## Usage
```javascript

var Soup = require("de.appwerft.soup").createDocument({
	url : "http://www.deutschlandfunk.de/irak-tote-und-verletzte-bei-anschlag-in-tikrit.1939.de.html?drn:news_id=721951"
	onload : function() {
		var res = Soup.getElementById("ati").getAttributes();
		console.log(res);
	} 
});
```
You can use all getters from [jsoup page](https://jsoup.org/cookbook/extracting-data/dom-navigation)

```javascript
var Soup = require("de.appwerft.soup").createDocument({
	url : "http://www.deutschlandfunk.de/hasskommentare-publizistin-domscheit-berg-sieht-krieg-gegen.1939.de.html?drn:news_id=721886"
	onload : function() {
		var elem = Soup.getElementById("ati");
		console.log(elem.firstElementSibling());
	} 
});
```
jQuery like selectors
---------------------
You can use [jQuery like selectors](https://jsoup.org/cookbook/extracting-data/selector-syntax) like:
```javascript
var Soup = require("de.appwerft.soup").createDocument({
	url : "http://www.deutschlandfunk.de/irak-tote-und-verletzte-bei-anschlag-in-tikrit.1939.de.html?drn:news_id=721951"
	onload : function() {
		var elems = Soup.select("img[src$=.png]");
		console.log(elems.getAttributes())
	} 
});
```

## Parsing local HTML

```javascript
var Soup = require("de.appwerft.soup").createDocument({
	html : "<html><body><div id="23" attr="ATTRIBUTE">CONTENT</div></body></html>"
});
Soup.getElementById("23").getAttributes();
```
## Overview methods Document
- [x] var elem = getElementById("id");
- [x] var elems = getElementsByClass("classname");
- [x] var elems = getElementsByTag("tagname");
- [x] var elems = getElementsByAttribute("alt")
- [x] var elems = select("cssSelector");


## Overview methods Element
- [x] var attrributes = getAttributes();
- [x] var value = getAttribute("src");
- [x] var text = getText();
- [x] var text = getOwnText(); 
- [x] getHtml();
- [x] toString()
- [x] getChildren();
- [x] getChild(ndx);
- [x] getSiblingElements();
- [x] getFirstElementSibling();
- [x] getLastElementSibling();
- [x] getNextElementSibling();
- [x] getPreviousElementSibling();
- [x] getClassNames();
- [x] hasClassName("needle");


## Parsing HTML to JSON
```javascript
var Soup = require("de.appwerft.soup").createJSONObject({
	url  : "https://www.heise.de/",
	onload : function(result) {
		console.log(result);
	}
});

```



Ti.Soup
=======
<img src="http://cdn1.javacodeexamples.com/wp-content/uploads/Jsoup-300x200.png" width=200 />
Titanium module for parsing remote HTML. It is Titanium version of Jsoup.

Usage
-----
```javascript

var Soup = require("de.appwerft.soup").createSoup({
	url : "http://www.deutschlandfunk.de/irak-tote-und-verletzte-bei-anschlag-in-tikrit.1939.de.html?drn:news_id=721951"
	onload : function() {
		var res = Soup.getElementById("ati").getAttributes();
		console.log(res);
	} 
});
```
You can use all getters from [jsoup page](https://jsoup.org/cookbook/extracting-data/dom-navigation)

```javascript
var Soup = require("de.appwerft.soup").createSoup({
	url : "http://www.deutschlandfunk.de/irak-tote-und-verletzte-bei-anschlag-in-tikrit.1939.de.html?drn:news_id=721951"
	onload : function() {
		var elem = Soup.getElementById("ati");
		console.log(elem.firstElementSibling());
	} 
});

```
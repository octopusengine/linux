# jqery

```
$(this).hide() - hides the current element
$("p").hide() - hides all <p> elements
$(".test").hide() - hides all elements with class="test"
$("#test").hide() - hides the element with id="test"
```

### Mouse Events	
```
click()
dblclick()
mouseenter()
mouseleave()
```

### Keyboard Events	
```
keypress()
keydown()
keyup()
```

### Form Events	
```
submit()
change()
focus()
blur()
```

### Document/Window Events
```
load()
resize()
scroll()
unload()
```

---
```
hide()
show()
fadeIn()
fadeOut()
fadeToggle()
fadeTo()
slideDown()
slideUp()
slideToggle()
```

```
animate()
stop()
css()
slideUp()
slideDown()
```

```
text() - Sets or returns the text content of selected elements
html() - Sets or returns the content of selected elements (including HTML markup)
val() - Sets or returns the value of form fields
```

```
append() - Inserts content at the end of the selected elements
prepend() - Inserts content at the beginning of the selected elements
after() - Inserts content after the selected elements
before() - Inserts content before the selected elements
remove() - Removes the selected element (and its child elements)
empty() - Removes the child elements from the selected element
addClass() - Adds one or more classes to the selected elements
removeClass() - Removes one or more classes from the selected elements
toggleClass() - Toggles between adding/removing classes from the selected elements
css() - Sets or returns the style attribute
```

```
width()
height()
innerWidth()
innerHeight()
outerWidth()
outerHeight()
```

```
parent()
parents()
parentsUntil()
children()
find()
siblings()
next()
nextAll()
nextUntil()
prev()
prevAll()
prevUntil()
```
...

```
<script src="js/jquery.min.js"></script>

<script>
$(document).ready(function() {
   $("#examples").hide();
   $("#ex").click(function(){ $("#examples").slideToggle("slow"); });
});
</script>

<button class="btn btn-warning" id="ex">Example...</button><br /><br />
<div class="fc" id="examples">
...
</div>

```

---

https://jquery.com/

https://www.w3schools.com/jquery/default.asp
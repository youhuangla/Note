我的第一个修改的Anki模板，ODH

```html
<!--front-->
<div class="section">
    <div id="front" class="items">{{expression}}<span class="audio">{{audio}}</span></div>

    {{#reading}}
    <hr>
    <div id="front-extra1" class="items">{{reading}}</div>
    {{/reading}}

</div>

<!--back-->

{{FrontSide}}

<div class="section">
    <div id="front" class="items">{{expression}}<span class="audio">{{audio}}</span></div>

    {{#reading}}
    <hr>
    <div id="front-extra1" class="items">{{reading}}</div>
    {{/reading}}

</div>

<div class="section">
    <div id="back" class="items">{{glossary}}</div>

    {{#sentence}}
    <hr>
    <div id="back-extra1" class="items">{{sentence}}</div>
    {{/sentence}}

    {{#extrainfo}}
    <hr>
    <div id="back-extra2" class="items">{{extrainfo}}</div>
    {{/extrainfo}}

</div>
```


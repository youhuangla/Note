# UML生成



[\ 译文\ 使用ChatGPT生成项目UML图：分步教程 \- 知乎](https://zhuanlan.zhihu.com/p/615138854)

[【必学】ChatGPT 1分钟搞定专业流程图 \- 知乎](https://zhuanlan.zhihu.com/p/613379279)

```
可以帮我生成上述代码的PlantUML代码吗？
```



[PlantText UML Editor](https://www.planttext.com/)

```
@startuml
title 前端架构图

rectangle "App.vue" as app {
    rectangle "路由\n路由配置\n路由守卫" as router
    rectangle "组件" as components {
        rectangle "ContentField" as content
        rectangle "NavBar" as nav 
        rectangle "GameMap\n" as game
        rectangle "MatchGround\nResultBoard" as match
    }

    rectangle "Vuex" as vuex { 
        rectangle "用户状态\n模块化" as user
        rectangle "对局状态\n模块化" as pk
    }
}

app --> router
app --> components
app ..> vuex
vuex ..> vuex
router -- user

components ..> router
components ..> vuex

rectangle "API 请求\naxios\njquery" as ajax

vuex ..> ajax

component "views" as views{
    rectangle "pk界面" as pk
    rectangle "rank界面" as rank
    rectangle "record界面"  as record
    rectangle "bot界面" as bot
}

router ..> views 
@enduml
```


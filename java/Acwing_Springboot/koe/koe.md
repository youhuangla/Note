```
.
├── App.vue
├── assets
│   ├── images
│   │   └── background.png
│   └── scripts
│       ├── AcGameObject.js
│       ├── Cell.js
│       ├── GameMap.js
│       ├── Snake.js
│       └── Wall.js
├── components
│   ├── ContentField.vue
│   ├── GameMap.vue
│   ├── NavBar.vue
│   └── PlayGround.vue
├── main.js
├── router
│   └── index.js
├── store
│   ├── index.js
│   └── user.js
└── views
    ├── error
    │   └── NotFound.vue
    ├── pk
    │   └── PkIndexView.vue
    ├── ranklist
    │   └── RanklistIndexView.vue
    ├── record
    │   └── RecordIndexView.vue
    └── user
        ├── account
        │   ├── UserAccountLoginView.vue
        │   └── UserAccountRegisterView.vue
        └── bot
            └── UserBotIndexView.vue               
```

这是一个vue项目的目录树





```css
<tbody>
                                <tr v-for="bot in bots" :key="bot.id">
                                    <td>{{ bot.title }}</td>
                                    <td>{{ bot.createtime }}</td>
                                    <td>
                                        <button type="button" class="btn btn-secondary" style="margin-right: 10px;"
                                            data-bs-toggle="modal"
                                            :data-bs-target="'#update-bot-modal-' + bot.id">修改</button>
                                        <button type="button" class="btn btn-danger" @click="remove_bot(bot)">删除</button>
                                        <!-- Modal -->
                                        <div class="modal fade" :id="'update-bot-modal-' + bot.id" tabindex="-1">
                                            <div class="modal-dialog modal-xl">
                                                <div class="modal-content">
                                                    <div class="modal-header">
                                                        <h1 class="modal-title fs-5">创建Bot</h1>
                                                        <button type="button" class="btn-close" data-bs-dismiss="modal"
                                                            aria-label="Close"></button>
                                                    </div>
                                                    <div class="modal-body">
                                                        <div class="mb-3">
                                                            <label for="add-bot-title" class="form-label">名称</label>
                                                            <input v-model="bot.title" type="text" class="form-control"
                                                                id="add-bot-title" placeholder="请输入Bot名称">
                                                        </div>
                                                        <div class="mb-3">
                                                            <label for="add-bot-description" class="form-label">简介</label>
                                                            <textarea v-model="bot.description" class="form-control"
                                                                id="add-bot-description" rows="3"
                                                                placeholder="请输入Bot简介"></textarea>
                                                        </div>
                                                        <div class="mb-3">
                                                            <label for="add-bot-code" class="form-label">代码</label>
                                                            <VAceEditor v-model:value="bot.content" @init="editorInit"
                                                                lang="c_cpp" theme="textmate" style="height: 300px" />
                                                        </div>
                                                    </div>
                                                    <div class="modal-footer">
                                                        <div class="error-message">{{ bot.error_message }}</div>
                                                        <button type="button" class="btn btn-primary"
                                                            @click="update_bot(bot)">保存修改</button>
                                                        <button type="button" class="btn btn-secondary"
                                                            data-bs-dismiss="modal">取消</button>
                                                    </div>
                                                </div>
                                            </div>
                                        </div>
                                    </td>
                                </tr>
                            </tbody>
```

分析以上代码，现在我想加入一个执行代码的功能，该如何修改？

>   ......







加入执行按钮

[Make Execute Button and post content to /bot/add link (be136e6b) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/be136e6b4227006c6606d851d49c23f79410c91c)

![image-20230425214028487](img/image-20230425214028487.png)





```css
<tbody>
    <tr v-for="bot in bots" :key="bot.id">
        <td>{{ bot.title }}</td>
        <td>{{ bot.createtime }}</td>
        <td>
            <button type="button" class="btn btn-secondary" style="margin-right: 10px;"
                data-bs-toggle="modal"
                :data-bs-target="'#update-bot-modal-' + bot.id">修改</button>
            <button type="button" class="btn btn-danger" @click="remove_bot(bot)">删除</button>
            <!-- 添加执行按钮 -->
            <button type="button" class="btn btn-success" @click="execute_bot(bot)">执行</button>
            <!-- Modal -->
            <div class="modal fade" :id="'update-bot-modal-' + bot.id" tabindex="-1">
                <div class="modal-dialog modal-xl">
                    <div class="modal-content">
                        <div class="modal-header">
                            <h1 class="modal-title fs-5">创建Bot</h1>
                            <button type="button" class="btn-close" data-bs-dismiss="modal"
                                aria-label="Close"></button>
                        </div>
                        <div class="modal-body">
                            <div class="mb-3">
                                <label for="add-bot-title" class="form-label">名称</label>
                                <input v-model="bot.title" type="text" class="form-control"
                                    id="add-bot-title" placeholder="请输入Bot名称">
                            </div>
                            <div class="mb-3">
                                <label for="add-bot-description" class="form-label">简介</label>
                                <textarea v-model="bot.description" class="form-control"
                                    id="add-bot-description" rows="3"
                                    placeholder="请输入Bot简介"></textarea>
                            </div>
                            <div class="mb-3">
                                <label for="add-bot-code" class="form-label">代码</label>
                                <VAceEditor v-model:value="bot.content" @init="editorInit"
                                    lang="c_cpp" theme="textmate" style="height: 300px" />
                            </div>
                        </div>
                        <div class="modal-footer">
                            <div class="error-message">{{ bot.error_message }}</div>
                            <button type="button" class="btn btn-primary"
                                @click="update_bot(bot)">保存修改</button>
                            <button type="button" class="btn btn-secondary"
                                data-bs-dismiss="modal">取消</button>
                        </div>
                    </div>
                </div>
            </div>
        </td>
    </tr>
</tbody>

```

在该表格的每一行下方加入一行，使之能显示图片<img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg==" alt="Red Square" />

![image-20230425214048241](img/image-20230425214048241.png)



```vue
<template>
    <div class="container">
        <div class="row">
            <div class="col-9">
                <div class="card" style="margin-top: 20px">
                    <div class="card-header">
                        <span style="font-size: 150%">我的Bot</span>
                        <button type="button" class="btn btn-primary float-end" data-bs-toggle="modal"
                            data-bs-target="#add-bot-btn">
                            创建Bot
                        </button>

                        <!-- Modal -->
                        <div class="modal fade" id="add-bot-btn" tabindex="-1">
                            <div class="modal-dialog modal-xl">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <h1 class="modal-title fs-5" id="exampleModalLabel">创建Bot</h1>
                                        <button type="button" class="btn-close" data-bs-dismiss="modal"
                                            aria-label="Close"></button>
                                    </div>
                                    <div class="modal-body">
                                        <div class="mb-3">
                                            <label for="add-bot-title" class="form-label">名称</label>
                                            <input v-model="botadd.title" type="text" class="form-control"
                                                id="add-bot-title" placeholder="请输入Bot名称">
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-description" class="form-label">简介</label>
                                            <textarea v-model="botadd.description" class="form-control"
                                                id="add-bot-description" rows="3" placeholder="请输入Bot简介"></textarea>
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-code" class="form-label">代码</label>
                                            <VAceEditor v-model:value="botadd.content" @init="editorInit" lang="c_cpp"
                                                theme="textmate" style="height: 300px" />
                                        </div>
                                    </div>
                                    <div class="modal-footer">
                                        <div class="error-message">{{ botadd.error_message }}</div>
                                        <button type="button" class="btn btn-primary" @click="add_bot">创建</button>
                                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">取消</button>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="card-body">
                        <table class="table table-striped table-hover">
                            <thead>
                                <tr>
                                    <th scope="col">名称</th>
                                    <th scope="col">创建时间</th>
                                    <th scope="col">操作</th>
                                </tr>
                            </thead>
                            <tbody>
                                <template v-for="(bot, index) in bots" :key="index">
                                    <tr>
                                        <td>{{ bot.title }}</td>
                                        <td>{{ bot.createtime }}</td>
                                        <td>
                                            <button type="button" class="btn btn-secondary" style="margin-right: 10px;"
                                                data-bs-toggle="modal"
                                                :data-bs-target="'#update-bot-modal-' + bot.id">修改</button>
                                            <button type="button" class="btn btn-danger"
                                                @click="remove_bot(bot)">删除</button>
                                            <!-- 添加执行按钮 -->
                                            <button type="button" class="btn btn-success"
                                                @click="update_bot(bot)">执行</button>
                                            <!-- Modal -->
                                            <div class="modal fade" :id="'update-bot-modal-' + bot.id" tabindex="-1">
                                                <div class="modal-dialog modal-xl">
                                                    <div class="modal-content">
                                                        <div class="modal-header">
                                                            <h1 class="modal-title fs-5">创建Bot</h1>
                                                            <button type="button" class="btn-close" data-bs-dismiss="modal"
                                                                aria-label="Close"></button>
                                                        </div>
                                                        <div class="modal-body">
                                                            <div class="mb-3">
                                                                <label for="add-bot-title" class="form-label">名称</label>
                                                                <input v-model="bot.title" type="text" class="form-control"
                                                                    id="add-bot-title" placeholder="请输入Bot名称">
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-description"
                                                                    class="form-label">简介</label>
                                                                <textarea v-model="bot.description" class="form-control"
                                                                    id="add-bot-description" rows="3"
                                                                    placeholder="请输入Bot简介"></textarea>
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-code" class="form-label">代码</label>
                                                                <VAceEditor v-model:value="bot.content" @init="editorInit"
                                                                    lang="c_cpp" theme="textmate" style="height: 300px" />
                                                            </div>
                                                        </div>
                                                        <div class="modal-footer">
                                                            <div class="error-message">{{ bot.error_message }}</div>
                                                            <button type="button" class="btn btn-success"
                                                                @click="update_bot(bot)">执行</button>
                                                            <button type="button" class="btn btn-primary"
                                                                @click="update_bot(bot)">保存修改</button>
                                                            <button type="button" class="btn btn-secondary"
                                                                data-bs-dismiss="modal">取消</button>
                                                        </div>
                                                        <!-- 将图片放在新的容器中 -->
                                                        <div class="modal-image">
                                                            <img src="data:image/png;base64,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"
                                                                alt="Red Square" />
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </td>
                                    </tr>
                                    <!-- 添加新行以显示图片 -->
                                    <tr>
                                        <td colspan="3">
                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                alt="Red Square" />
                                        </td>
                                    </tr>
                                </template>
                            </tbody>



                        </table>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import { ref, reactive } from "vue";
import $ from 'jquery'
import { useStore } from "vuex"
import { Modal } from 'bootstrap/dist/js/bootstrap'
import { VAceEditor } from 'vue3-ace-editor';
import ace from 'ace-builds';


export default {
    components: {
        VAceEditor
    },
    setup() {
        ace.config.set(
            "basePath",
            "https://cdn.jsdelivr.net/npm/ace-builds@" + require('ace-builds').version + "/src-noconflict/")

        const store = useStore();
        let bots = ref([]);

        const botadd = reactive({
            title: "",
            description: "",
            content: "",
            error_message: "",
        })

        const refresh_bots = () => {
            $.ajax({
                url: "http://localhost:3000/user/bot/getlist/",
                type: 'GET',
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    bots.value = resp;
                }
            })
        }

        refresh_bots();

        const add_bot = () => {
            botadd.error_message = "";
            $.ajax({
                url: "http://localhost:3000/user/bot/add/",
                type: 'POST',
                data: {
                    title: botadd.title,
                    description: botadd.description,
                    content: botadd.content,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        refresh_bots();
                        botadd.title = "";
                        botadd.description = "";
                        botadd.content = "";
                        Modal.getInstance("#add-bot-btn").hide();
                    } else {
                        botadd.error_message = resp.error_message;
                    }
                }
            })
        }

        const remove_bot = (bot) => {
            $.ajax({
                url: "http://localhost:3000/user/bot/remove/",
                type: 'POST',
                data: {
                    bot_id: bot.id,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        refresh_bots();
                    }
                }
            })
        }


        const update_bot = (bot) => {
            botadd.error_message = "";

            $.ajax({
                url: "http://localhost:3000/user/bot/update/",
                type: 'POST',
                data: {
                    bot_id: bot.id,
                    title: bot.title,
                    description: bot.description,
                    content: bot.content,
                    image: bot.image,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        Modal.getInstance('#update-bot-modal-' + bot.id).hide();
                        refresh_bots();
                    } else {
                        bot.error_message = resp.error_message;
                    }
                }
            })
        }
        return {
            bots,
            botadd,
            add_bot,
            remove_bot,
            update_bot,
        }
    }
}
</script>

<style scoped>
div.error-message {
    color: red;
}
</style>
```

在以上代码中，我点击“修改”按钮后弹出一个模态框，之后点击“执行”按钮，如何使点击执行按钮后







[add a tiger picture in modal of Pk page (ab5fafa0) · Commits · you huang / kob · GitLab (acwing.com)](https://git.acwing.com/youhuang/kob/-/commit/ab5fafa0431c0a34773cf5797a4a49e5c395ffaa)

![image-20230426120722103](img/image-20230426120722103.png)







```
<template>
    <div class="container">
        <div class="row">
            <div class="col-9">
                <div class="card" style="margin-top: 20px">
                    <div class="card-header">
                        <span style="font-size: 150%">我的Bot</span>
                        <button type="button" class="btn btn-primary float-end" data-bs-toggle="modal"
                            data-bs-target="#add-bot-btn">
                            创建Bot
                        </button>

                        <!-- Modal -->
                        <div class="modal fade" id="add-bot-btn" tabindex="-1">
                            <div class="modal-dialog modal-xl">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <h1 class="modal-title fs-5" id="exampleModalLabel">创建Bot</h1>
                                        <button type="button" class="btn-close" data-bs-dismiss="modal"
                                            aria-label="Close"></button>
                                    </div>
                                    <div class="modal-body">
                                        <div class="mb-3">
                                            <label for="add-bot-title" class="form-label">名称</label>
                                            <input v-model="botadd.title" type="text" class="form-control"
                                                id="add-bot-title" placeholder="请输入Bot名称">
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-description" class="form-label">简介</label>
                                            <textarea v-model="botadd.description" class="form-control"
                                                id="add-bot-description" rows="3" placeholder="请输入Bot简介"></textarea>
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-code" class="form-label">代码</label>
                                            <VAceEditor v-model:value="botadd.content" @init="editorInit" lang="c_cpp"
                                                theme="textmate" style="height: 300px" />
                                        </div>
                                    </div>
                                    <div class="modal-footer">
                                        <div class="error-message">{{ botadd.error_message }}</div>
                                        <button type="button" class="btn btn-primary" @click="add_bot">创建</button>
                                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">取消</button>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="card-body">
                        <table class="table table-striped table-hover">
                            <thead>
                                <tr>
                                    <th scope="col">名称</th>
                                    <th scope="col">创建时间</th>
                                    <th scope="col">操作</th>
                                </tr>
                            </thead>
                            <tbody>
                                <template v-for="(bot, index) in bots" :key="index">
                                    <tr>
                                        <td>{{ bot.title }}</td>
                                        <td>{{ bot.createtime }}</td>
                                        <td>
                                            <button type="button" class="btn btn-secondary" style="margin-right: 10px;"
                                                data-bs-toggle="modal"
                                                :data-bs-target="'#update-bot-modal-' + bot.id">修改</button>
                                            <button type="button" class="btn btn-danger"
                                                @click="remove_bot(bot)">删除</button>
                                            <!-- 添加执行按钮 -->
                                            <button type="button" class="btn btn-success"
                                                @click="update_bot(bot)">执行</button>
                                            <!-- Modal -->
                                            <div class="modal fade" :id="'update-bot-modal-' + bot.id" tabindex="-1">
                                                <div class="modal-dialog modal-xl">
                                                    <div class="modal-content">
                                                        <div class="modal-header">
                                                            <h1 class="modal-title fs-5">创建Bot</h1>
                                                            <button type="button" class="btn-close" data-bs-dismiss="modal"
                                                                aria-label="Close"></button>
                                                        </div>
                                                        <div class="modal-body">
                                                            <div class="mb-3">
                                                                <label for="add-bot-title" class="form-label">名称</label>
                                                                <input v-model="bot.title" type="text" class="form-control"
                                                                    id="add-bot-title" placeholder="请输入Bot名称">
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-description"
                                                                    class="form-label">简介</label>
                                                                <textarea v-model="bot.description" class="form-control"
                                                                    id="add-bot-description" rows="3"
                                                                    placeholder="请输入Bot简介"></textarea>
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-code" class="form-label">代码</label>
                                                                <VAceEditor v-model:value="bot.content" @init="editorInit"
                                                                    lang="c_cpp" theme="textmate" style="height: 300px" />
                                                            </div>
                                                        </div>
                                                        <div class="modal-footer">
                                                            <div class="error-message">{{ bot.error_message }}</div>
                                                            <button type="button" class="btn btn-success"
                                                                @click="update_bot(bot)">执行</button>
                                                            <button type="button" class="btn btn-primary"
                                                                @click="update_bot(bot)">保存修改</button>
                                                            <button type="button" class="btn btn-secondary"
                                                                data-bs-dismiss="modal">取消</button>
                                                        </div>
                                                        <!-- 将图片放在新的容器中 -->
                                                        <div class="modal-image">
                                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                                alt="Red Square" />
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </td>
                                    </tr>
                                    <!-- 添加新行以显示图片 -->
                                </template>
                            </tbody>



                        </table>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import { ref, reactive } from "vue";
import $ from 'jquery'
import { useStore } from "vuex"
import { Modal } from 'bootstrap/dist/js/bootstrap'
import { VAceEditor } from 'vue3-ace-editor';
import ace from 'ace-builds';


export default {
    components: {
        VAceEditor
    },
    setup() {
        ace.config.set(
            "basePath",
            "https://cdn.jsdelivr.net/npm/ace-builds@" + require('ace-builds').version + "/src-noconflict/")

        const store = useStore();
        let bots = ref([]);

        const botadd = reactive({
            title: "",
            description: "",
            content: "",
            error_message: "",
        })

        const refresh_bots = () => {
            $.ajax({
                url: "http://localhost:3000/user/bot/getlist/",
                type: 'GET',
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    bots.value = resp;
                }
            })
        }

        refresh_bots();

        const add_bot = () => {
            botadd.error_message = "";
            $.ajax({
                url: "http://localhost:3000/user/bot/add/",
                type: 'POST',
                data: {
                    title: botadd.title,
                    description: botadd.description,
                    content: botadd.content,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        refresh_bots();
                        botadd.title = "";
                        botadd.description = "";
                        botadd.content = "";
                        Modal.getInstance("#add-bot-btn").hide();
                    } else {
                        botadd.error_message = resp.error_message;
                    }
                }
            })
        }

        const remove_bot = (bot) => {
            $.ajax({
                url: "http://localhost:3000/user/bot/remove/",
                type: 'POST',
                data: {
                    bot_id: bot.id,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        refresh_bots();
                    }
                }
            })
        }

        /*
                const update_bot = (bot) => {
                    botadd.error_message = "";
        
                    $.ajax({
                        url: "http://localhost:3000/user/bot/update/",
                        type: 'POST',
                        data: {
                            bot_id: bot.id,
                            title: bot.title,
                            description: bot.description,
                            content: bot.content,
                            image: bot.image,
                        },
                        headers: {
                            Authorization: "Bearer " + store.state.user.token,
                        },
                        success(resp) {
                            if (resp.error_message === "success") {
                                Modal.getInstance('#update-bot-modal-' + bot.id).hide();
                                refresh_bots();
                            } else {
                                bot.error_message = resp.error_message;
                            }
                        }
                    })
                }
        */
        const update_bot = (bot) => {
            botadd.error_message = "";

            $.ajax({
                url: "http://localhost:3000/user/bot/update/",
                type: "POST",
                data: {
                    bot_id: bot.id,
                    title: bot.title,
                    description: bot.description,
                    content: bot.content,
                    image: bot.image,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        console.log("image:" + bot.image)
                        Modal.getInstance("#update-bot-modal-" + bot.id).hide();
                        refresh_bots();
                    } else {
                        bot.error_message = resp.error_message;
                    }
                },
            });
        };

        return {
            bots,
            botadd,
            add_bot,
            remove_bot,
            update_bot,
        }
    }
}
</script>

<style scoped>
div.error-message {
    color: red;
}
</style>
```

现在bot.image中存储的是byte[]类型，byte[]类型保存一张图片的base64编码，如何将update_bot函数中的bot.image显示成图片？



base64值





现在我想用MySQL数据库存储一个base64的图片值，如何用Java将base64    我将BLOB类型的







```java
package com.kob.backend.utils;

import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.util.Base64;
import javax.imageio.ImageIO;
import org.json.JSONObject;

public class TextToImageConverter {
    private final String url = "http://region-3.seetacloud.com:20357/sdapi/v1/txt2img";

    public String convertTextToImage(String text) throws Exception {
        // 设置POST请求的请求体数据
        JSONObject requestBody = new JSONObject();
        requestBody.put("prompt", text);
        requestBody.put("steps", 50);
        requestBody.put("sampler_index", "DDIM");
        requestBody.put("negative_prompt", "EasyNegative,badhandv4,");
        requestBody.put("firstphase_width", 256);
        requestBody.put("firstphase_height", 256);
        requestBody.put("seed", 1);

        // 创建HttpURLConnection对象并设置请求方法和请求头
        java.net.URL connectionUrl = new java.net.URL(url);
        java.net.HttpURLConnection connection = (java.net.HttpURLConnection) connectionUrl.openConnection();
        connection.setRequestMethod("POST");
        connection.setRequestProperty("Content-Type", "application/json");
        connection.setDoOutput(true);

        // 将请求体数据写入请求流
        java.io.DataOutputStream outputStream = new java.io.DataOutputStream(connection.getOutputStream());
        outputStream.write(requestBody.toString().getBytes("UTF-8"));
        outputStream.flush();
        outputStream.close();

        // 获取响应数据
        int responseCode = connection.getResponseCode();
        java.io.BufferedReader bufferedReader = new java.io.BufferedReader(new java.io.InputStreamReader(connection.getInputStream()));
        StringBuilder response = new StringBuilder();
        String line;
        while ((line = bufferedReader.readLine()) != null) {
            response.append(line);
        }
        bufferedReader.close();

        // 解析响应数据中的Base64编码的字符串并将其转换为PNG图片
        JSONObject jsonResponse = new JSONObject(response.toString());
        String base64Image = jsonResponse.getJSONArray("images").getString(0);
        byte[] imageBytes = Base64.getDecoder().decode(base64Image);
        ByteArrayInputStream bis = new ByteArrayInputStream(imageBytes);
        BufferedImage image = ImageIO.read(bis);

        // 将图片保存为PNG格式的文件
        File output = new File("output.png");
        ImageIO.write(image, "png", output);

        // 将图片转换为Base64编码
        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        ImageIO.write(image, "png", bos);
        byte[] base64Bytes = Base64.getEncoder().encode(bos.toByteArray());
        String base64ImageString = new String(base64Bytes, "UTF-8");

        base64ImageString = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg==";
        // 打印响应数据和保存的文件路径
        //System.out.println("Response Code: " + responseCode);
        //System.out.println("Response Body: " + response.toString());
        System.out.println("Image saved at " + output.getAbsolutePath());

        return base64ImageString;
    }
}

```

```java
<template>
    <div class="container">
        <div class="row">
            <div class="col-9">
                <div class="card" style="margin-top: 20px">
                    <div class="card-header">
                        <span style="font-size: 150%">我的Bot</span>
                        <button type="button" class="btn btn-primary float-end" data-bs-toggle="modal"
                            data-bs-target="#add-bot-btn">
                            创建Bot
                        </button>

                        <!-- Modal -->
                        <div class="modal fade" id="add-bot-btn" tabindex="-1">
                            <div class="modal-dialog modal-xl">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <h1 class="modal-title fs-5" id="exampleModalLabel">创建Bot</h1>
                                        <button type="button" class="btn-close" data-bs-dismiss="modal"
                                            aria-label="Close"></button>
                                    </div>
                                    <div class="modal-body">
                                        <div class="mb-3">
                                            <label for="add-bot-title" class="form-label">名称</label>
                                            <input v-model="botadd.title" type="text" class="form-control"
                                                id="add-bot-title" placeholder="请输入Bot名称">
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-description" class="form-label">简介</label>
                                            <textarea v-model="botadd.description" class="form-control"
                                                id="add-bot-description" rows="3" placeholder="请输入Bot简介"></textarea>
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-code" class="form-label">代码</label>
                                            <VAceEditor v-model:value="botadd.content" @init="editorInit" lang="c_cpp"
                                                theme="textmate" style="height: 300px" />
                                        </div>
                                    </div>
                                    <div class="modal-footer">
                                        <div class="error-message">{{ botadd.error_message }}</div>
                                        <button type="button" class="btn btn-primary" @click="add_bot">创建</button>
                                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">取消</button>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="card-body">
                        <table class="table table-striped table-hover">
                            <thead>
                                <tr>
                                    <th scope="col">名称</th>
                                    <th scope="col">创建时间</th>
                                    <th scope="col">操作</th>
                                </tr>
                            </thead>
                            <tbody>
                                <template v-for="(bot, index) in bots" :key="index">
                                    <tr>
                                        <td>{{ bot.title }}</td>
                                        <td>{{ bot.createtime }}</td>
                                        <td>
                                            <button type="button" class="btn btn-secondary" style="margin-right: 10px;"
                                                data-bs-toggle="modal"
                                                :data-bs-target="'#update-bot-modal-' + bot.id">修改</button>
                                            <button type="button" class="btn btn-danger"
                                                @click="remove_bot(bot)">删除</button>
                                            <!-- 添加执行按钮 -->
                                            <button type="button" class="btn btn-success"
                                                @click="update_bot(bot)">执行</button>
                                            <!-- Modal -->
                                            <div class="modal fade" :id="'update-bot-modal-' + bot.id" tabindex="-1">
                                                <div class="modal-dialog modal-xl">
                                                    <div class="modal-content">
                                                        <div class="modal-header">
                                                            <h1 class="modal-title fs-5">创建Bot</h1>
                                                            <button type="button" class="btn-close" data-bs-dismiss="modal"
                                                                aria-label="Close"></button>
                                                        </div>
                                                        <div class="modal-body">
                                                            <div class="mb-3">
                                                                <label for="add-bot-title" class="form-label">名称</label>
                                                                <input v-model="bot.title" type="text" class="form-control"
                                                                    id="add-bot-title" placeholder="请输入Bot名称">
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-description"
                                                                    class="form-label">简介</label>
                                                                <textarea v-model="bot.description" class="form-control"
                                                                    id="add-bot-description" rows="3"
                                                                    placeholder="请输入Bot简介"></textarea>
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-code" class="form-label">代码</label>
                                                                <VAceEditor v-model:value="bot.content" @init="editorInit"
                                                                    lang="c_cpp" theme="textmate" style="height: 300px" />
                                                            </div>
                                                        </div>
                                                        <div class="modal-footer">
                                                            <div class="error-message">{{ bot.error_message }}</div>
                                                            <button type="button" class="btn btn-success"
                                                                @click="update_bot(bot)">执行</button>
                                                            <button type="button" class="btn btn-primary"
                                                                @click="update_bot(bot)">保存修改</button>
                                                            <button type="button" class="btn btn-secondary"
                                                                data-bs-dismiss="modal">取消</button>
                                                        </div>
                                                        <!-- 将图片放在新的容器中 -->
                                                        <!--div class="modal-image">
                                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                                alt="Red Square" />
                                                        </div-->
                                                        <!--div class="modal-image">
                                                            <img :src="'data:image/png;base64,' + bot.image"
                                                                alt="Bot Image" />
                                                        </div-->
                                                        <div class="modal-image">
                                                            <img :src="'data:image/png;base64,' + btoa(String.fromCharCode(...new Uint8Array(bot.image.data)))"
                                                                alt="Bot Image" />
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </td>
                                    </tr>
                                    <!-- 添加新行以显示图片 -->
                                    <tr>
                                        <td colspan="3">
                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                alt="Red Square" />
                                            <img :src="image" />
                                        </td>
                                    </tr>
                                </template>
                            </tbody>



                        </table>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import { ref, reactive } from "vue";
import $ from 'jquery'
import { useStore } from "vuex"
import { Modal } from 'bootstrap/dist/js/bootstrap'
import { VAceEditor } from 'vue3-ace-editor';
import ace from 'ace-builds';


export default {
    components: {
        VAceEditor
    },
    setup() {
        ace.config.set(
            "basePath",
            "https://cdn.jsdelivr.net/npm/ace-builds@" + require('ace-builds').version + "/src-noconflict/")

        const store = useStore();
        let bots = ref([]);

        const botadd = reactive({
            title: "",
            description: "",
            content: "",
            error_message: "",
        })

        const refresh_bots = () => {
            $.ajax({
                url: "http://localhost:3000/user/bot/getlist/",
                type: 'GET',
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    bots.value = resp;
                }
            })
        }

        refresh_bots();

        const add_bot = () => {
            botadd.error_message = "";
            $.ajax({
                url: "http://localhost:3000/user/bot/add/",
                type: 'POST',
                data: {
                    title: botadd.title,
                    description: botadd.description,
                    content: botadd.content,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        refresh_bots();
                        botadd.title = "";
                        botadd.description = "";
                        botadd.content = "";
                        Modal.getInstance("#add-bot-btn").hide();
                    } else {
                        botadd.error_message = resp.error_message;
                    }
                }
            })
        }

        const remove_bot = (bot) => {
            $.ajax({
                url: "http://localhost:3000/user/bot/remove/",
                type: 'POST',
                data: {
                    bot_id: bot.id,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        refresh_bots();
                    }
                }
            })
        }

       
        const update_bot = (bot) => {
            botadd.error_message = "";

            $.ajax({
                url: "http://localhost:3000/user/bot/update/",
                type: "POST",
                data: {
                    bot_id: bot.id,
                    title: bot.title,
                    description: bot.description,
                    content: bot.content,
                    image: bot.image,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        console.log('data:image/png;base64,' + bot.image);
                        Modal.getInstance("#update-bot-modal-" + bot.id).hide();
                        refresh_bots();
                    } else {
                        bot.error_message = resp.error_message;
                    }
                },
            });
        };

        return {
            bots,
            botadd,
            add_bot,
            remove_bot,
            update_bot,
        }
    }
}
</script>

<style scoped>
div.error-message {
    color: red;
}
</style>
```

为什么工具类中的函数convertTextToImage不能成功使用？







```vue
<template>
    <div class="container">
        <div class="row">
            <div class="col-9">
                <div class="card" style="margin-top: 20px">
                    <div class="card-header">
                        <span style="font-size: 150%">我的Bot</span>
                        <button type="button" class="btn btn-primary float-end" data-bs-toggle="modal"
                            data-bs-target="#add-bot-btn">
                            创建Bot
                        </button>

                        <!-- Modal -->
                        <div class="modal fade" id="add-bot-btn" tabindex="-1">
                            <div class="modal-dialog modal-xl">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <h1 class="modal-title fs-5" id="exampleModalLabel">创建Bot</h1>
                                        <button type="button" class="btn-close" data-bs-dismiss="modal"
                                            aria-label="Close"></button>
                                    </div>
                                    <div class="modal-body">
                                        <div class="mb-3">
                                            <label for="add-bot-title" class="form-label">名称</label>
                                            <input v-model="botadd.title" type="text" class="form-control"
                                                id="add-bot-title" placeholder="请输入Bot名称">
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-description" class="form-label">简介</label>
                                            <textarea v-model="botadd.description" class="form-control"
                                                id="add-bot-description" rows="3" placeholder="请输入Bot简介"></textarea>
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-code" class="form-label">代码</label>
                                            <VAceEditor v-model:value="botadd.content" @init="editorInit" lang="c_cpp"
                                                theme="textmate" style="height: 300px" />
                                        </div>
                                    </div>
                                    <div class="modal-footer">
                                        <div class="error-message">{{ botadd.error_message }}</div>
                                        <button type="button" class="btn btn-primary" @click="add_bot">创建</button>
                                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">取消</button>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="card-body">
                        <table class="table table-striped table-hover">
                            <thead>
                                <tr>
                                    <th scope="col">名称</th>
                                    <th scope="col">创建时间</th>
                                    <th scope="col">操作</th>
                                </tr>
                            </thead>
                            <tbody>
                                <template v-for="(bot, index) in bots" :key="index">
                                    <tr>
                                        <td>{{ bot.title }}</td>
                                        <td>{{ bot.createtime }}</td>
                                        <td>
                                            <button type="button" class="btn btn-secondary" style="margin-right: 10px;"
                                                data-bs-toggle="modal"
                                                :data-bs-target="'#update-bot-modal-' + bot.id">修改</button>
                                            <button type="button" class="btn btn-danger"
                                                @click="remove_bot(bot)">删除</button>
                                            <!-- 添加执行按钮 -->
                                            <button type="button" class="btn btn-success"
                                                @click="update_bot(bot)">执行</button>
                                            <!-- Modal -->
                                            <div class="modal fade" :id="'update-bot-modal-' + bot.id" tabindex="-1">
                                                <div class="modal-dialog modal-xl">
                                                    <div class="modal-content">
                                                        <div class="modal-header">
                                                            <h1 class="modal-title fs-5">创建Bot</h1>
                                                            <button type="button" class="btn-close" data-bs-dismiss="modal"
                                                                aria-label="Close"></button>
                                                        </div>
                                                        <div class="modal-body">
                                                            <div class="mb-3">
                                                                <label for="add-bot-title" class="form-label">名称</label>
                                                                <input v-model="bot.title" type="text" class="form-control"
                                                                    id="add-bot-title" placeholder="请输入Bot名称">
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-description"
                                                                    class="form-label">简介</label>
                                                                <textarea v-model="bot.description" class="form-control"
                                                                    id="add-bot-description" rows="3"
                                                                    placeholder="请输入Bot简介"></textarea>
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-code" class="form-label">代码</label>
                                                                <VAceEditor v-model:value="bot.content" @init="editorInit"
                                                                    lang="c_cpp" theme="textmate" style="height: 300px" />
                                                            </div>
                                                        </div>
                                                        <div class="modal-footer">
                                                            <div class="error-message">{{ bot.error_message }}</div>
                                                            <!--button type="button" class="btn btn-success"
                                                                @click="update_bot(bot)">执行</button-->
                                                            <button type="button" class="btn btn-success" @click="execute_bot(bot)" data-bs-dismiss="">执行</button>
                                                            <button type="button" class="btn btn-primary"
                                                                @click="update_bot(bot)">保存修改</button>
                                                            <button type="button" class="btn btn-secondary"
                                                                data-bs-dismiss="modal">取消</button>
                                                        </div>
                                                        <!-- 将图片放在新的容器中 -->
                                                        <!--div class="modal-image">
                                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                                alt="Red Square" />
                                                        </div-->
                                                        <!--div class="modal-image">
                                                            <img :src="'data:image/png;base64,' + bot.image"
                                                                alt="Bot Image" />
                                                        </div-->
                                                        <div>
                                                            {{ getBase64ImageUrl(bot.image) }}
                                                            <img :src="getBase64ImageUrl(bot.image)" alt="Bot Image" />
                                                        </div>


                                                    </div>
                                                </div>
                                            </div>
                                        </td>
                                    </tr>
                                    <!-- 添加新行以显示图片 -->
                                    <tr>
                                        <td colspan="3">
                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                alt="Red Square" />
                                            <img :src="image" />
                                        </td>
                                    </tr>
                                </template>
                            </tbody>



                        </table>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import { ref, reactive } from "vue";
import $ from 'jquery'
import { useStore } from "vuex"
import { Modal } from 'bootstrap/dist/js/bootstrap'
import { VAceEditor } from 'vue3-ace-editor';
import ace from 'ace-builds';



export default {
    components: {
        VAceEditor
    },
    setup() {
        ace.config.set(
            "basePath",
            "https://cdn.jsdelivr.net/npm/ace-builds@" + require('ace-builds').version + "/src-noconflict/")

        const store = useStore();
        let bots = ref([]);

        const botadd = reactive({
            title: "",
            description: "",
            content: "",
            error_message: "",
        })

        const refresh_bots = () => {
            $.ajax({
                url: "http://localhost:3000/user/bot/getlist/",
                type: 'GET',
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    bots.value = resp;
                }
            })
        }

        refresh_bots();


        const update_bot = (bot) => {
            botadd.error_message = "";

            $.ajax({
                url: "http://localhost:3000/user/bot/update/",
                type: "POST",
                data: {
                    bot_id: bot.id,
                    title: bot.title,
                    description: bot.description,
                    content: bot.content,
                    image: bot.image,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        console.log('data:image/png;base64,' + bot.image);
                        Modal.getInstance("#update-bot-modal-" + bot.id).hide();
                        refresh_bots();
                    } else {
                        bot.error_message = resp.error_message;
                    }
                },
            });
        };
        const execute_bot = (bot) => {
            botadd.error_message = "";

            $.ajax({
                url: "http://localhost:3000/user/bot/update/",
                type: "POST",
                data: {
                    bot_id: bot.id,
                    title: bot.title,
                    description: bot.description,
                    content: bot.content,
                    image: bot.image,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        console.log('data:image/png;base64,' + bot.image);
                        //Modal.getInstance("#update-bot-modal-" + bot.id).hide();
                        refresh_bots();
                    } else {
                        bot.error_message = resp.error_message;
                    }
                },
            });
        };

        const getBase64ImageUrl = (blob) => {
            if (blob) {
                //console.log("getBase64ImageUrl");
                const byteArray = new Uint8Array(blob);
                const base64Data = btoa(
                    byteArray.reduce((data, byte) => data + String.fromCharCode(byte), "")
                );
                return "data:image/png;base64," + base64Data;
            } else {
                return "";
            }
        };

        return {
            bots,
            botadd,
            add_bot,
            remove_bot,
            update_bot,
            execute_bot,
            getBase64ImageUrl,
        }
    }
}
</script>

<style scoped>
div.error-message {
    color: red;
}
</style>

```

execute_bot 函数执行后，模态框中仍然无法显示图片，为什么？



在Spring框架的后端中

```
        String base64ImageString = converter.convertTextToImage(content);
        byte[] new_image = convertStringToByteArray(base64ImageString); 
        Bot new_bot = new Bot(
                bot.getId(),
                user.getId(),
                title,
                description,
                content,
                bot.getRating(),
                bot.getCreatetime(),
                new Date(),
                image
        );
```

最后image存到了数据库中，使用vue框架的前端如何从image中还原图片？







```css
<tbody>
                                <template v-for="(bot, index) in bots" :key="index">
                                    <tr>
                                        <td>{{ bot.title }}</td>
                                        <td>{{ bot.createtime }}</td>
                                        <td>
                                            <button type="button" class="btn btn-secondary" style="margin-right: 10px;"
                                                data-bs-toggle="modal"
                                                :data-bs-target="'#update-bot-modal-' + bot.id">修改</button>
                                            <button type="button" class="btn btn-danger"
                                                @click="remove_bot(bot)">删除</button>
                                            <!-- 添加执行按钮 -->
                                            <button type="button" class="btn btn-success"
                                                @click="update_bot(bot)">执行</button>
                                            <!-- Modal -->
                                            <div class="modal fade" :id="'update-bot-modal-' + bot.id" tabindex="-1">
                                                <div class="modal-dialog modal-xl">
                                                    <div class="modal-content">
                                                        <div class="modal-header">
                                                            <h1 class="modal-title fs-5">创建Bot</h1>
                                                            <button type="button" class="btn-close" data-bs-dismiss="modal"
                                                                aria-label="Close"></button>
                                                        </div>
                                                        <div class="modal-body">
                                                            <div class="mb-3">
                                                                <label for="add-bot-title" class="form-label">名称</label>
                                                                <input v-model="bot.title" type="text" class="form-control"
                                                                    id="add-bot-title" placeholder="请输入Bot名称">
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-description"
                                                                    class="form-label">简介</label>
                                                                <textarea v-model="bot.description" class="form-control"
                                                                    id="add-bot-description" rows="3"
                                                                    placeholder="请输入Bot简介"></textarea>
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-code" class="form-label">代码</label>
                                                                <VAceEditor v-model:value="bot.content" @init="editorInit"
                                                                    lang="c_cpp" theme="textmate" style="height: 300px" />
                                                            </div>
                                                        </div>
                                                        <div class="modal-footer">
                                                            <div class="error-message">{{ bot.error_message }}</div>
                                                            <!--button type="button" class="btn btn-success"
                                                                @click="update_bot(bot)">执行</button-->
                                                            <button type="button" class="btn btn-success"
                                                                @click="execute_bot(bot)" data-bs-dismiss="">执行</button>
                                                            <button type="button" class="btn btn-primary"
                                                                @click="update_bot(bot)">保存修改</button>
                                                            <button type="button" class="btn btn-secondary"
                                                                data-bs-dismiss="modal">取消</button>
                                                        </div>
                                                        <!-- 将图片放在新的容器中 -->
                                                        <!--div class="modal-image">
                                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                                alt="Red Square" />
                                                        </div-->
                                                        <!--div class="modal-image">
                                                            <img :src="'data:image/png;base64,' + bot.image"
                                                                alt="Bot Image" />
                                                        </div-->
                                                        <div>
                                                            <!--img :src="getBase64ImageUrl(bot.image)" alt="Bot Image" /-->
                                                            <!--img :src="getBase64ImageUrl(image(bot).value)" /-->
                                                            <img :src="'data:image/png;base64,' + bot.image"
                                                                alt="Bot Image" />
                                                            <!--img :src="image(bot).value" alt="Bot Image" /-->
                                                            <!--img :src="image(bot).value" alt="Bot Image" /-->
                                                            <!--img :src="imageBase64[bot.id]" alt="Bot Image" /-->

                                                        </div>
                                                        <img :src="imageWithPrefix" alt="还原的图片">
                                                        <div>
                                                            <h1>{{ bot.title }}</h1>
                                                            <p>{{ bot.description }}</p>
                                                            <p>{{ bot.content }}</p>
                                                            <p>{{ bot.image }}</p> <!-- 打印 Base64 编码的图像数据 -->
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </td>
                                    </tr>
                                    <!-- 添加新行以显示图片 -->
                                    <!--tr>
                                        <td colspan="3">
                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                alt="Red Square" />
                                            <img :src="image" />
                                        </td>
                                    </tr-->
                                </template>
                            </tbody>
```

如果要在这里使用呢？









```java
package com.kob.backend.mapper.service.impl.user.bot;

import com.kob.backend.mapper.BotMapper;
import com.kob.backend.mapper.service.impl.utils.UserDetailsImpl;
import com.kob.backend.mapper.service.user.bot.UpdateService;
import com.kob.backend.pojo.Bot;
import com.kob.backend.pojo.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.HashMap;
import java.util.Map;

import com.kob.backend.utils.TextToImageConverter;
import com.kob.backend.utils.StringToByteArrayUtils;

import static com.kob.backend.utils.StringToByteArrayUtils.convertStringToByteArray;
@Service
public class UpdateServiceImpl implements UpdateService {

    @Autowired
    private BotMapper botMapper;

    @Override
    public Map<String, String> update(Map<String, String> data) throws Exception {
        UsernamePasswordAuthenticationToken authenticationToken =
                (UsernamePasswordAuthenticationToken) SecurityContextHolder.getContext().getAuthentication();
        UserDetailsImpl loginUser = (UserDetailsImpl) authenticationToken.getPrincipal();
        User user = loginUser.getUser();

        int bot_id = Integer.parseInt(data.get("bot_id"));

        String title = data.get("title");
        String description = data.get("description");
        String content = data.get("content");
        byte[] image = data.get("image").getBytes();
        //System.out.printf("image: %s", image);
        Map<String, String> map = new HashMap<>();

        if (title == null || title.length() == 0) {
            map.put("error_message", "标题不能为空");
            return map;
        }

        if (title.length() > 100) {
            map.put("error_message", "标题长度不能大于100");
            return map;
        }

        if (description == null || description.length() == 0) {
            description = "这个用户很懒，什么都没留下~";
        }

        if (description.length() > 300) {
            map.put("error_message", "Bot描述长度不能超过300");
            return map;
        }

        if (content == null || content.length() == 0) {
            map.put("error_message", "代码不能为空");
            return map;
        }

        if (content.length() > 10000) {
            map.put("error_message", "代码长度不能超过10000");
            return map;
        }

        Bot bot = botMapper.selectById(bot_id);

        if (bot == null) {
            map.put("error_message", "Bot不存在或已被删除");
            return map;
        }

        if (!bot.getUserId().equals(user.getId())) {
            map.put("error_message", "你没有权限修改该Bot");
            return map;
        }
        TextToImageConverter converter = new TextToImageConverter();
        String base64ImageString = converter.convertTextToImage(content);
        byte[] new_image = convertStringToByteArray(base64ImageString);
        System.out.println("Debug");
        image = new_image;
        Bot new_bot = new Bot(
                bot.getId(),
                user.getId(),
                title,
                description,
                content,
                bot.getRating(),
                bot.getCreatetime(),
                new Date(),
                image
        );
        System.out.printf(base64ImageString);
        botMapper.updateById(new_bot);

        map.put("error_message", "success");

        return map;
    }
}
```

这段代码能不能在map中返回base64ImageString呢？前端中使用

```vue
$.ajax({
                url: "http://localhost:3000/user/bot/update/",
                type: "POST",
                data: {
                    bot_id: bot.id,
                    title: bot.title,
                    description: bot.description,
                    content: bot.content,
                    image: bot.image,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },

                success(resp) {
                    if (resp.error_message === "success") {
                        console.log('data:image/png;base64,' + bot.image);
                        console.log(resp);
                        //Modal.getInstance("#update-bot-modal-" + bot.id).hide();
                        refresh_bots();
                    } else {
                        bot.error_message = resp.error_message;
                    }
                },
            });
```

如何取出base64ImageString？







```vue
const execute_bot = (bot) => {
            botadd.error_message = "";

            $.ajax({
                url: "http://localhost:3000/user/bot/update/",
                type: "POST",
                data: {
                    bot_id: bot.id,
                    title: bot.title,
                    description: bot.description,
                    content: bot.content,
                    image: bot.image,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },

                success(resp) {
                    if (resp.error_message === "success") {
                        const base64ImageString = resp.base64ImageString;
                        console.log('data:image/png;base64,' + base64ImageString);
                        
                        //Modal.getInstance("#update-bot-modal-" + bot.id).hide();
                        refresh_bots();
                    } else {
                        bot.error_message = resp.error_message;
                    }
                },
            });
        };
```

接着，如何将base64ImageString的值传递到

```
                            <tbody>
                                <template v-for="(bot, index) in bots" :key="index">
                                    <tr>
                                        <td>{{ bot.title }}</td>
                                        <td>{{ bot.createtime }}</td>
                                        <td>
                                            <button type="button" class="btn btn-secondary" style="margin-right: 10px;"
                                                data-bs-toggle="modal"
                                                :data-bs-target="'#update-bot-modal-' + bot.id">修改</button>
                                            <button type="button" class="btn btn-danger"
                                                @click="remove_bot(bot)">删除</button>
                                            <!-- 添加执行按钮 -->
                                            <button type="button" class="btn btn-success"
                                                @click="update_bot(bot)">执行</button>
                                            <!-- Modal -->
                                            <div class="modal fade" :id="'update-bot-modal-' + bot.id" tabindex="-1">
                                                <div class="modal-dialog modal-xl">
                                                    <div class="modal-content">
                                                        <div class="modal-header">
                                                            <h1 class="modal-title fs-5">创建Bot</h1>
                                                            <button type="button" class="btn-close" data-bs-dismiss="modal"
                                                                aria-label="Close"></button>
                                                        </div>
                                                        <div class="modal-body">
                                                            <div class="mb-3">
                                                                <label for="add-bot-title" class="form-label">名称</label>
                                                                <input v-model="bot.title" type="text" class="form-control"
                                                                    id="add-bot-title" placeholder="请输入Bot名称">
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-description"
                                                                    class="form-label">简介</label>
                                                                <textarea v-model="bot.description" class="form-control"
                                                                    id="add-bot-description" rows="3"
                                                                    placeholder="请输入Bot简介"></textarea>
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-code" class="form-label">代码</label>
                                                                <VAceEditor v-model:value="bot.content" @init="editorInit"
                                                                    lang="c_cpp" theme="textmate" style="height: 300px" />
                                                            </div>
                                                        </div>
                                                        <div class="modal-footer">
                                                            <div class="error-message">{{ bot.error_message }}</div>
                                                            <!--button type="button" class="btn btn-success"
                                                                @click="update_bot(bot)">执行</button-->
                                                            <button type="button" class="btn btn-success"
                                                                @click="execute_bot(bot)" data-bs-dismiss="">执行</button>
                                                            <button type="button" class="btn btn-primary"
                                                                @click="update_bot(bot)">保存修改</button>
                                                            <button type="button" class="btn btn-secondary"
                                                                data-bs-dismiss="modal">取消</button>
                                                        </div>
                                                        <!-- 将图片放在新的容器中 -->
                                                        <!--div class="modal-image">
                                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                                alt="Red Square" />
                                                        </div-->
                                                        <!--div class="modal-image">
                                                            <img :src="'data:image/png;base64,' + bot.image"
                                                                alt="Bot Image" />
                                                        </div-->
                                                        <div>
                                                            <!--img :src="getBase64ImageUrl(bot.image)" alt="Bot Image" /-->
                                                            <!--img :src="getBase64ImageUrl(image(bot).value)" /-->
                                                            <!--img :src="'data:image/png;base64,' + bot.image"
                                                                alt="Bot Image" /-->
                                                            <!--img :src="image(bot).value" alt="Bot Image" /-->
                                                            <!--img :src="image(bot).value" alt="Bot Image" /-->
                                                            <!--img :src="imageBase64[bot.id]" alt="Bot Image" /-->
                                                            <img :src="getBase64ImageUrl(bot)">
                                                            <img :src="'data:image/png;base64,' + bot.image" alt="Bot Image">

                                                            <h1>{{ bot.title }}</h1>
                                                            <p>{{ bot.description }}</p>
                                                            <p>{{ bot.content }}</p>
                                                            <p>{{ bot.image }}</p> <!-- 打印 Base64 编码的图像数据 -->
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </td>
                                    </tr>
                                    <!-- 添加新行以显示图片 -->
                                    <!--tr>
                                        <td colspan="3">
                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                alt="Red Square" />
                                            <img :src="image" />
                                        </td>
                                    </tr-->
                                </template>
                            </tbody>
```







```
<template>
    <div class="container">
        <div class="row">
            <div class="col-9">
                <div class="card" style="margin-top: 20px">
                    <div class="card-header">
                        <span style="font-size: 150%">我的Bot</span>
                        <button type="button" class="btn btn-primary float-end" data-bs-toggle="modal"
                            data-bs-target="#add-bot-btn">
                            创建Bot
                        </button>

                        <!-- Modal -->
                        <div class="modal fade" id="add-bot-btn" tabindex="-1">
                            <div class="modal-dialog modal-xl">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <h1 class="modal-title fs-5" id="exampleModalLabel">创建Bot</h1>
                                        <button type="button" class="btn-close" data-bs-dismiss="modal"
                                            aria-label="Close"></button>
                                    </div>
                                    <div class="modal-body">
                                        <div class="mb-3">
                                            <label for="add-bot-title" class="form-label">名称</label>
                                            <input v-model="botadd.title" type="text" class="form-control"
                                                id="add-bot-title" placeholder="请输入Bot名称">
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-description" class="form-label">简介</label>
                                            <textarea v-model="botadd.description" class="form-control"
                                                id="add-bot-description" rows="3" placeholder="请输入Bot简介"></textarea>
                                        </div>
                                        <div class="mb-3">
                                            <label for="add-bot-code" class="form-label">代码</label>
                                            <VAceEditor v-model:value="botadd.content" @init="editorInit" lang="c_cpp"
                                                theme="textmate" style="height: 300px" />
                                        </div>
                                    </div>
                                    <div class="modal-footer">
                                        <div class="error-message">{{ botadd.error_message }}</div>
                                        <button type="button" class="btn btn-primary" @click="add_bot">创建</button>
                                        <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">取消</button>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="card-body">
                        <table class="table table-striped table-hover">
                            <thead>
                                <tr>
                                    <th scope="col">名称</th>
                                    <th scope="col">创建时间</th>
                                    <th scope="col">操作</th>
                                </tr>
                            </thead>
                            <tbody>
                                <template v-for="(bot, index) in bots" :key="index">
                                    <tr>
                                        <td>{{ bot.title }}</td>
                                        <td>{{ bot.createtime }}</td>
                                        <td>
                                            <button type="button" class="btn btn-secondary" style="margin-right: 10px;"
                                                data-bs-toggle="modal"
                                                :data-bs-target="'#update-bot-modal-' + bot.id">修改</button>
                                            <button type="button" class="btn btn-danger"
                                                @click="remove_bot(bot)">删除</button>
                                            <!-- 添加执行按钮 -->
                                            <button type="button" class="btn btn-success"
                                                @click="update_bot(bot)">执行</button>
                                            <!-- Modal -->
                                            <div class="modal fade" :id="'update-bot-modal-' + bot.id" tabindex="-1">
                                                <div class="modal-dialog modal-xl">
                                                    <div class="modal-content">
                                                        <div class="modal-header">
                                                            <h1 class="modal-title fs-5">创建Bot</h1>
                                                            <button type="button" class="btn-close" data-bs-dismiss="modal"
                                                                aria-label="Close"></button>
                                                        </div>
                                                        <div class="modal-body">
                                                            <div class="mb-3">
                                                                <label for="add-bot-title" class="form-label">名称</label>
                                                                <input v-model="bot.title" type="text" class="form-control"
                                                                    id="add-bot-title" placeholder="请输入Bot名称">
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-description"
                                                                    class="form-label">简介</label>
                                                                <textarea v-model="bot.description" class="form-control"
                                                                    id="add-bot-description" rows="3"
                                                                    placeholder="请输入Bot简介"></textarea>
                                                            </div>
                                                            <div class="mb-3">
                                                                <label for="add-bot-code" class="form-label">代码</label>
                                                                <VAceEditor v-model:value="bot.content" @init="editorInit"
                                                                    lang="c_cpp" theme="textmate" style="height: 300px" />
                                                            </div>
                                                        </div>
                                                        <div class="modal-footer">
                                                            <div class="error-message">{{ bot.error_message }}</div>
                                                            <!--button type="button" class="btn btn-success"
                                                                @click="update_bot(bot)">执行</button-->
                                                            <button type="button" class="btn btn-success"
                                                                @click="execute_bot(bot)" data-bs-dismiss="">执行</button>
                                                            <button type="button" class="btn btn-primary"
                                                                @click="update_bot(bot)">保存修改</button>
                                                            <button type="button" class="btn btn-secondary"
                                                                data-bs-dismiss="modal">取消</button>
                                                        </div>

                                                        <div>

                                                            <img :src="getBase64ImageUrl(bot)" alt="Bot Image">


                                                            <h1>{{ bot.title }}</h1>
                                                            <p>{{ bot.description }}</p>
                                                            <p>{{ bot.content }}</p>
                                                            <p>{{ getBase64ImageUrl(bot) }}</p> <!-- 打印 Base64 编码的图像数据 -->
                                                        </div>
                                                    </div>
                                                </div>
                                            </div>
                                        </td>
                                    </tr>
                                    <!-- 添加新行以显示图片 -->
                                    <!--tr>
                                        <td colspan="3">
                                            <img src="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAAUAAAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO9TXL0Y4OHwAAAABJRU5ErkJggg=="
                                                alt="Red Square" />
                                            <img :src="image" />
                                        </td>
                                    </tr-->
                                </template>
                            </tbody>



                        </table>
                    </div>
                </div>
            </div>
        </div>
    </div>
</template>

<script>
import { ref, reactive } from "vue";
import $ from 'jquery'
import { useStore } from "vuex"
import { Modal } from 'bootstrap/dist/js/bootstrap'
import { VAceEditor } from 'vue3-ace-editor';
import ace from 'ace-builds';

export default {
    components: {
        VAceEditor
    },

    computed: {
        getBase64ImageUrl() {
            return bot => 'data:image/png;base64,' + (bot.base64ImageString || '');
        },
    },
    setup() {


        ace.config.set(
            "basePath",
            "https://cdn.jsdelivr.net/npm/ace-builds@" + require('ace-builds').version + "/src-noconflict/")

        const store = useStore();
        let bots = ref([]);

        const botadd = reactive({
            title: "",
            description: "",
            content: "",
            error_message: "",
        })
        const refresh_bots = () => {
            $.ajax({
                url: "http://localhost:3000/user/bot/getlist/",
                type: 'GET',
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    // 为每个 bot 对象添加 base64ImageString 属性
                    bots.value = resp.map((bot) => {
                        return {
                            ...bot,
                            base64ImageString: bot.base64ImageString || '',
                        };
                    });
                }

            })
        }
        refresh_bots();

        const update_bot = (bot) => {
            botadd.error_message = "";

            $.ajax({
                url: "http://localhost:3000/user/bot/update/",
                type: "POST",
                data: {
                    bot_id: bot.id,
                    title: bot.title,
                    description: bot.description,
                    content: bot.content,
                    image: bot.image,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },
                success(resp) {
                    if (resp.error_message === "success") {
                        const base64ImageString = resp.base64ImageString;
                        console.log('data:image/png;base64,' + base64ImageString);

                        // 将 base64ImageString 添加到 bot 对象中
                        //const updatedBot = Object.assign({}, bot, { base64ImageString });
                        //Modal.getInstance("#update-bot-modal-" + bot.id).hide();

                        refresh_bots();
                    } else {
                        bot.error_message = resp.error_message;
                    }
                },
            });
        };
        const execute_bot = (bot) => {
            botadd.error_message = "";

            $.ajax({
                url: "http://localhost:3000/user/bot/update/",
                type: "POST",
                data: {
                    bot_id: bot.id,
                    title: bot.title,
                    description: bot.description,
                    content: bot.content,
                    image: bot.image,
                },
                headers: {
                    Authorization: "Bearer " + store.state.user.token,
                },

                success(resp) {
                    if (resp.error_message === "success") {
                        const base64ImageString = resp.base64ImageString;
                        console.log('data:image/png;base64,' + base64ImageString);

                        // 将 base64ImageString 添加到 bot 对象中
                        const updatedBot = Object.assign({}, bot, { base64ImageString });

                        // 使用更新后的 bot 对象调用 update_bot
                        update_bot(updatedBot);

                        //Modal.getInstance("#update-bot-modal-" + bot.id).hide();
                        refresh_bots();
                    } else {
                        bot.error_message = resp.error_message;
                    }
                },
            });
        };

```

 为什么点击“执行”，模态框中的图片不会自动更新？

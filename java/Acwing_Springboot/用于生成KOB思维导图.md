## 后端

- BackendApplication.java
- config/
  - CorsConfig.java
  - SecurityConfig.java
  - filter/
    - JwtAuthenticationTokenFilter.java
- controller/
  - pk/
    - BotInfoController.java
    - IndexController.java
  - user/
    - account/
      - InfoController.java
      - LoginController.java
      - RegisterController.java
    - bot/
      - AddController.java
      - GetListController.java
      - RemoveController.java
      - UpdateController.java
- mapper/
  - BotMapper.java
  - UserMapper.java
  - service/
    - impl/
      - UserDetailsServiceImpl.java
      - user/
        - account/
          - InfoServiceImpl.java
          - LoginServiceImpl.java
          - RegisterServiceImpl.java
        - bot/
          - AddServiceImpl.java
          - GetListServiceImpl.java
          - RemoveServiceImpl.java
          - UpdateServiceImpl.java
    - user/
      - account/
        - InfoService.java
        - LoginService.java
        - RegisterService.java
      - bot/
        - AddService.java
        - GetListService.java
        - RemoveService.java
        - UpdateService.java
  - pojo/
    - Bot.java
    - User.java
  - utils/
    - JwtUtil.java

## 前端

- main.js
- assets/
  - scripts/
    - AcGameObject.js
    - Cell.js
    - GameMap.js
    - Snake.js
    - Wall.js
  - router/
    - index.js
  - store/
    - index.js
    - user.js
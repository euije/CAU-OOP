Name: 이의제
StudentID: 20190197

How to compile
- OS type : macOS 13.0.1(22A400)
- compiler type/version
    - vscode
        - 1.73.1 (Universal)
    - g++ 17
        - Apple clang version 13.1.6 (clang-1316.0.21.2.3)
        - Target: x86_64-apple-darwin22.1.0

How to execute
- compilation method
    - requires: Xcode, vscode installation
    - compile: Click the "C/C++ 파일 실행" button(⌃ + ⌥ + N)
        - .vscode file is required to execute the program
        - If you fail to execute the program, try to command the following lines.

- Execuable file
    - 'opengl_arkanoid'
    - Enter "./opengl_arkanoid" command in your bash of macOS

```
g++ -fdiagnostics-color=always -g /Users/euije/Github/CAU-OOP/20190197_proj3/opengl_arkanoid.cpp -g /Users/euije/Github/CAU-OOP/20190197_proj3/csphere.cpp -g /Users/euije/Github/CAU-OOP/20190197_proj3/cwall.cpp -I//Users/euije/Github/CAU-OOP/20190197_proj3/csphere.h -I//Users/euije/Github/CAU-OOP/20190197_proj3/cwall.h -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Headers -L/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -o /Users/euije/Github/CAU-OOP/20190197_proj3/opengl_arkanoid -framework OpenGL -framework GLUT
```

Summary of Your Code Modification
1. Make CSphere, CWall module (modulization)
2. Move Leftbutton to Rightbutton to rotate camera perspective
3. Add "void PassiveMotionCallback(int x, int y)" function to handle mouse motion in real-time
4. Make functional lines to check collision between objects in "void renderScene"
    - Case1) Cwall - CSphere Collision
    - Case2) CSphere - CSphere Collision
    - My first trial to handle movement was to make module of Vector.
        - However, Vector requires a lot of mathematical operation.
        - So, Funtion to check collision between objects didn't work properly.
5. if you want to move red sphere, press '1' in your keyboard then move if via MouseLeftButton,
    - If you want to move yellow sphere, press alphabet ('a' to 'o'--there are 15 yellow spheres) in your keyboard then move if via MouseLeftButton.
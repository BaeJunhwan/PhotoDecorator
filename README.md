# Photo Decorator

사용자가 업로드한 PNG 이미지를 편집할 수 있는 C++ 기반 사진 편집 프로그램입니다.  
이미지를 정사각형 비율로 자르고, 필터를 적용한 뒤 액자와 스티커를 추가하여 결과 이미지를 생성합니다.

## Features
- PNG 이미지 읽기 및 저장
- SNS 피드에 적합한 정사각형 이미지 생성
- Gray scale, invert, bright, sepia 등 필터 적용
- 사각형, 원형, 클로버형 등 다양한 액자 추가
- 산타 모자, 콧수염, 트리 등 스티커 추가

## Tech Stack
- C++
- libpng
- GCC
- Makefile

## How to Run

```bash
make
./editor_exe sogang.png out.png
```

## What I learned

* PNG 이미지를 픽셀 단위로 읽고 수정하며 이미지 파일이 메모리에서 어떻게 표현되는지 이해했습니다.
* RGB 값과 alpha 값을 직접 조작하여 필터 적용, 액자 추가, 스티커 합성 기능을 구현했습니다.
* 기능별로 소스 파일을 분리하며 프로그램 구조를 모듈화하는 방법을 학습했습니다.
* Makefile을 활용해 여러 C++ 소스 파일을 컴파일하고 실행 파일을 생성하는 과정을 경험했습니다.

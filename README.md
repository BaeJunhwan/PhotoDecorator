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

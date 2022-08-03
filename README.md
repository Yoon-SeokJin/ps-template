# ps-template

PS를 할 때 유용한 탬플릿입니다.

`ps.cpp`에서 문제를 풉니다.

컴파일 시 -DLOCAL 파라미터를 붙여 LOCAL을 define하면 아래와 같은 기능이 지원됩니다.

1. `input.txt`에서 테스트케이스를 입력받을 수 있습니다.

2. `show`함수를 사용할 수 있습니다. tuple을 제외한 모든 C++ STL을 예쁘게 출력하는 제네릭 함수입니다. 디버깅할 때 사용합니다. `show.hpp`에 정의되어있습니다.

LOCAL이 define되어있지 않으면 입력은 표준 입출력으로 받아지고 `show`함수는 무시됩니다.

OJ시스템에는 LOCAL이 define되도록 하는 -DLOCAL 파라미터가 없을 것이므로 아무 수정을 하지 않고 제출하면 됩니다.

`input_generator.ipynb`에서 테스트케이스를 파이썬으로 만들 수 있습니다.

`time_calc.cpp`에서 실행시간을 측정할 수 있습니다.

`time_plot.ipynb`에서 위에서 측정한 결과를 그래프로 그려볼 수 있습니다.

`.clang-format`에서 cpp코드 스타일을 고정할 수 있습니다.

`vscode_env`는 위 코드가 정상적으로 실행되는 visual code 환경입니다. 폴더명을 `.vscode`로 바꾸면 적용됩니다.

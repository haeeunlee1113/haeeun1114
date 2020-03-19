# Ex1 - 이해은

- word 타입의 형태로 작성해 주셨는데, ex2처럼 colab 환경에서의 jupyter notebook으로 문서를 작성해서 github에 공유해주셔야 합니다.

  - Colab에서  `save in github` 을 이용하시면 편합니다.

- Colab 환경 setting 과정에서 google drive mount를 한 statement가 확인되지 않습니다. 

  - https://course.fast.ai/start_colab.html 와
    - 특히 step 4 : Saving your data files를 이해하시면 하단의 이미지 첨부 또한 하실 수 있으리라 봅니다.
  - Extended Syllabus에서 ex1의 setting을 참고하시면 됩니다.

- ex1에서의 statement 를 실행한 사진들을 캡쳐해 올려주셨는데, 각 statement의 코드들을 잘 이해했는지 확인할 수 있는 comment(#으로 작성, 또는 그 외 markdown) 들을 작성하지 않으셨습니다.

  - 혹시 이해가 안 가시는 부분들은 앞으로의 과제 해결을 위해 조사하시고, 그래도 모르시는 부분이 있다면 comment로 작성하시어 물어보셔도 됩니다.(jacinthe 조교의 guide 문서 참고)

- 앞으로의 lesson 및 과제 수행을 위해서 ex1에서 환경에 대한 이해가 필수적입니다.

  - 아래 항목에서 세부 항목들이 어떤 의미를 가지는지 잘 이해하셨으면 합니다.

  1. colab의 google server 내의 폴더(/content/gdrive/My Drive)를 유저의 google drive에 연결하는 코드.

  ```python
  from google.colab import drive
  drive.mount('/content/gdrive', force_remount=True)
  root_dir = "/content/gdrive/My Drive/"
  base_dir = root_dir + 'fastai-v3/
  ```

  - drive.mount('/content/gdrive')
  - rood_dir
  - base_di

  2. colab에서 파이선 명령어 실행을 위한 기본적인 library 설치

  ```bash
  !curl -s https://course.fast.ai/setup/colab | bash
  ```

  - ​	!
  - curl
  - |
  - bash

  3. Markdown

     - code cell vs markdown cell

     - *Italic*

     - **Bold** 

     - `inline`

     - > blockquote

     - [링크](www.naver.com)

     - 그 외 list, heading

  4. mounted된 drive에 folder 생성

     - colab 문서에 예시가 우리의 예시와 달라 제가 작성한 코드를 첨부하였습니다. 왜 이렇게 썼는지 이해하시기 바랍니다.

     ```python
     folder = 'images'
     path = Path(base_dir + 'data/notebook_tutorial')
     dest = path/folder
     dest.mkdir(parents=True, exist_ok=True)
     ```

     - subfolder 생성
     - Path 위치 및 변수의 값
     - dest 위치 및 변수의 값
     - mkdir의미
     - dest가 mkdir을 갖는 이유

  5. image 첨부

     - 제가 작성한 코드입니다. 학생분께서 작성하시는 directory(folder) 위치와 값은 다를 수 있습니다.

     ```python
     Image.open(base_dir+'data/notebook_tutorial/images/fileStructure.png')
     ```

     - Image.open()
     - base_dir

  6. doc()

  7. help()



### 이미지를 불러 올 수 없는 이유, 이미지 위치를 저장하는 법을 질문해주셨는데, 위의 사항들을 잘 이해하신다면 직접 해결하실 수 있을 것 같습니다. 혹시 다음주 월요일까지 해결이 어려우시다면, 제게 메일로 물어보셔도 됩니다!!



### EX2 는 ipyn 파일로 올려주셨기에, ex2는 올려주신 jupyter notebook에 feedback을 올리겠습니다.




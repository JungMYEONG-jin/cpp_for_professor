## https://github.com/VundleVim/Vundle.vim
- Quick start에들어가서 하라는대로 설치
- 그리고 ctags 설치
### - sudo apt-get install exuberant-ctags
### - Plugin 'xolox/vim-easytags' vimrc에 추가
- Misc 설치하라나오면 설치해야함

set tag=./tags;/
let g:easytags_async=1 
let g:easytags_auto_highlight = 0
let g:easytags_include_members = 1
let g:easytags_dynamic_files = 1

- 설치후 해당 스크립추가


### - sudo apt-get install cscope
- cscope를 vim에서 편하게 쓸 수 있도록 도와주는 quickr-cscope.vim 플러그인을 설치한다.

### -Plugin 'ronakg/quickr-cscope.vim'
- plugin추가


function! LoadCscope()
  let db = findfile("cscope.out", ".;")
  if (!empty(db))
    let path = strpart(db, 0, match(db, "/cscope.out$"))
    set nocscopeverbose " suppress 'duplicate connection' error
    exe "cs add " . db . " " . path
    set cscopeverbose
  " else add the database pointed to by environment variable 
  elseif $CSCOPE_DB != "" 
    cs add $CSCOPE_DB
  endif
endfunction
au BufEnter /* call LoadCscope()

- 해당 스크립트도 추가

### - build는 cscope -RUbq로함



- 태그 안되면 해당 스크립 추가

set cscopetag
set csto=0
set tags=./tags,tags;/
cs add cscope.out

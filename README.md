## Homework for Lab02
### Группа: ИУ8-21, Студент: Осипова О.

<details>
  <summary>Part I</summary>
  <p>
  <br>&nbsp;&nbsp;&nbsp;1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).<br>
  Создаем пустой репозиторий <i>lab02_hw</i> через веб-интерфейс.
    
  2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдущем шаге.
    
  ```
  $ git init
  $ git remote add origin https://github.com/lockeystorm/lab02_hw.git
  $ git pull origin master
  $ touch README.md && git add README.md
  $ git commit -m "first commit"
  $ git push -u origin master
  ```
  Инициализируем репозиторий, связываем его с удаленным репозиторием, созданным на предыдущем шаге, загружаем оттуда данные (чтобы не было конфликтов).
  
  Создаем локально файл README.md и добавляем его в репозиторий, создаем первый коммит "first commit" и отправляем изменения на удаленный репозиторий.
    
  <br>3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу Hello world на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.
  
  ```
  $ touch hello_world.cpp
  $ cat > hello_world.cpp <<EOF
  > #include <iostream>
  > 
  > using namespace std;
  > 
  > int main() {
  >     cout << "Hello, World!" << endl;
  >     return 0;
  > }
  > EOF
  ```
  Создаем файл hello_world.cpp и реализуем в нем программу Hello World на языке C++.
  
  <br>4. Добавьте этот файл в локальную копию репозитория.
  ```
  $ git add hello_world.cpp
  ```
  Добавление файла в локальный репозиторий(теперь изменения в нем отслеживаются).
  
  <br>5. Закоммитьте изменения с осмысленным сообщением.
  ```
  $ git commit -m "added hello_world.cpp bad codestyle"
  [master d6e3abc] added hello_world.cpp bad codestyle
   1 file changed, 8 insertions(+)
   create mode 100644 hello_world.cpp
  ```
  Флаг -m позволяет добавить описание к комииту.
  
  <br>6. Измените исходный код так, чтобы программа через стандартный поток ввода запрашивала имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.
  ```
  $ vim hello_world.cpp
  ```
  Изменим программу через текстовый редактор.
  
  <br>7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?
  ```
  $ git commit -am "changed hello_world.cpp to hello world from <username>"
  [master 9bf230b] changed hello_world.cpp to hello world from <username>
   1 file changed, 5 insertions(+), 1 deletion(-)
  ```
  `git add` не нужно использовать, так как файл hello_world.cpp уже добавлен в локальный репозиторий и Git уже отслеживает изменеия в нем.
  
  `git commit -am "message"` автоматически добавляет в коммит все изменения в отслеживаемых файлах.
  
  <br>8. Запушьте изменения в удалённый репозиторий.
  ```
  $ git push
  Enumerating objects: 5, done.
  Counting objects: 100% (5/5), done.
  Compressing objects: 100% (3/3), done.
  Writing objects: 100% (3/3), 419 bytes | 69.00 KiB/s, done.
  Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
  remote: Resolving deltas: 100% (1/1), completed with 1 local object.
  To https://github.com/lockeystorm/lab02_hw.git
     f12035e..9bf230b  master -> master
  ```
  В данном случае можно не использовать `git push origin master`, так как ранее мы уже указывали ветке master следить за удаленной веткой origin/master.
  
  <br>9. Проверьте, что история коммитов доступна в удалённом репозитории.
  ```
  $ git log --oneline origin/master
  9bf230b (HEAD -> master, origin/master) changed hello_world.cpp to hello world from <username>
  f12035e Update minor mistake in hello_world.cpp
  d6e3abc added hello_world.cpp bad codestyle
  2f6e32c first commit
  1f81043 Initial commit

  $ git log --oneline
  9bf230b (HEAD -> master, origin/master) changed hello_world.cpp to hello world from <username>
  f12035e Update minor mistake in hello_world.cpp
  d6e3abc added hello_world.cpp bad codestyle
  2f6e32c first commit
  1f81043 Initial commit
  ```
  Запускаем `git log --oneline <branch_name>`, чтобы посмотреть историю коммиов на локальной и удаленной ветке.
  
  Флаг `--oneline` позволяет выводить все коммиты в одну строку, без подробной информации, параметр <branch_name> не указан во втором случае, так как это текущая ветка.
  
  История коммитов совпала, значит, она доступна в удаленном репозитории.
  
  </p>
</details>

<details>
  <summary>Part II</summary>
  <p>
  <br>&nbsp;&nbsp;&nbsp;1. В локальной копии репозитория создайте локальную ветку `patch1`.
    
    ```
    $ git checkout -b patch1
    Switched to a new branch 'patch1'
    ```
    
    git checkout -b patch1 - перемещаемся на ветку patch1 (флаг -b показывает, что эту ветку надо создать) (вместо этого можно использовать две команды: git branch patch1 и git checkout patch1).
    
  <br>2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.
  ```
  $ vim hello_world.cpp
  ```
  Воспользуемся текстовым редактором.
  
  <br>3. commit, push локальную ветку в удалённый репозиторий.
  ```
  $ git commit -am "removed 'using namespace std'"
  [patch1 77dc793] removed 'using namespace std'
   1 file changed, 5 insertions(+), 7 deletions(-)
  
  $ git push -u origin patch1
  Enumerating objects: 5, done.
  Counting objects: 100% (5/5), done.
  Compressing objects: 100% (3/3), done.
  Writing objects: 100% (3/3), 403 bytes | 403.00 KiB/s, done.
  Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
  remote: Resolving deltas: 100% (1/1), completed with 1 local object.
  remote: 
  remote: Create a pull request for 'patch1' on GitHub by visiting:
  remote:      https://github.com/lockeystorm/lab02_hw/pull/new/patch1
  remote: 
  To https://github.com/lockeystorm/lab02_hw.git
   * [new branch]      patch1 -> patch1
  branch 'patch1' set up to track 'origin/patch1'.
  ```
  `git push -u origin patch1` - отправляем изменения в удаленную ветку origin/patch1 и говорим ветке patch1 следить за веткой origin/patch1 удаленного репозитория.
  
  <br>4. Проверьте, что ветка `patch1` доступна в удалённом репозитории.
  ```
  $ git ls-remote origin patch1
  77dc79360a7aef7c6bfcb4783e59d20d0fb66376	refs/heads/patch1
  ```
  Команда `git ls-remote origin patch1` проверяет наличие ветки `patch1` в удаленном репозитории, выводит хеш последнего коммита в этой ветке и ссылку на нее.
  `git ls-remote` — показывает информацию о ссылках (ветках, тегах) в удаленном репозитории.
  Если ветки нет, вывод будет пустым.
  
  <br>5. Создайте pull-request `patch1 -> master`.<br>
  ```base: master <- compare:patch1  Able to merge. These branches can be automatically merged.```
  [Созданный pull-request](https://github.com/lockeystorm/lab02_hw/blob/master/pull-request-master-patch1%20pt.%20II%20%235.png)
  
  <br>6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
  ```
  $ vim hello_world.cpp
  ```
  
  <br>7. commit, push.
  ```
  $ git commit -am "added comments to hello_world.cpp"
  $ git push
  ```

  <br>8. Проверьте, что новые изменения есть в созданном на шаге 5 pull-request.<br>
  Коммиты отображаются и в созданном ранее [pull-request'е](https://github.com/lockeystorm/lab02_hw/blob/master/check%20pt.%20II%20%238.png)
  
  <br>9. В удалённый репозиторий выполните слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.<br>
  [Ветки успешно объединены](https://github.com/lockeystorm/lab02_hw/blob/master/PR%20merge%20pt.%20II%20%239.png)
  
  <br>10. Локально выполните pull.
  ```
  $ git checkout master
  $ git pull
  remote: Enumerating objects: 1, done.
  remote: Counting objects: 100% (1/1), done.
  remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
  Unpacking objects: 100% (1/1), 905 bytes | 905.00 KiB/s, done.
  From https://github.com/lockeystorm/lab02_hw
     9bf230b..eddd190  master     -> origin/master
  Updating 9bf230b..eddd190
  Fast-forward
   hello_world.cpp | 12 +++++-------
   1 file changed, 5 insertions(+), 7 deletions(-)
  ```
  Переключаемся на ветку `master` и выполняем pull.
  
  <br>11. С помощью команды `git log` просмотрите историю в локальной версии ветки `master`.<br>
    [Вывод истории коммитов](https://github.com/lockeystorm/lab02_hw/blob/master/history_of_commits.txt)
    
  <br>12. Удалите локальную ветку `patch1`.
  ```
  $ git branch -d patch1
  Deleted branch patch1 (was 9f34459).
  
  $ git fetch -p
  From https://github.com/lockeystorm/lab02_hw
   - [deleted]         (none)     -> origin/patch1
  ```
  Сначала удаляем локальную ветку, потом удаляем локальную ссылку на удаленную ветку.
  </p>
</details>

<details>
  <summary>Part III</summary>
  <p>
  <br>&nbsp;&nbsp;&nbsp;1. Создайте новую локальную ветку `patch2`.<br>
    
  ```
  $ git checkout -b patch2
  Switched to a new branch 'patch2'
  ```
  Используем ту же команду, что и при создании `patch1`.
  
  <br>2. Измените *code style* с помощью утилиты *clang-format*. Например, используя опцию `-style=Mozilla`.
  ```
  $ clang-format -i -style=Mozilla hello_world.cpp
  ```
  -i - применить изменения для файла hello_world.cpp.
  
  <br>3. commit, push, создайте pull-request `patch2 -> master`.
  ```
  $ git commit -am "change codestyle of hello_world.cpp"
  [patch2 7ac9995] change codestyle of hello_world.cpp
   1 file changed, 8 insertions(+), 6 deletions(-)
  
  $ git push -u origin patch2
  Enumerating objects: 5, done.
  Counting objects: 100% (5/5), done.
  Compressing objects: 100% (3/3), done.
  Writing objects: 100% (3/3), 364 bytes | 364.00 KiB/s, done.
  Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
  remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
  remote: 
  remote: Create a pull request for 'patch2' on GitHub by visiting:
  remote:      https://github.com/lockeystorm/lab02_hw/pull/new/patch2
  remote: 
  To https://github.com/lockeystorm/lab02_hw.git
   * [new branch]      patch2 -> patch2
  branch 'patch2' set up to track 'origin/patch2'.
  ```
  Используем команды из аналогичных пунктов второй части, pull-request создаем через github.com.
  
  <br>4. В ветке `master` в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.<br>
  Делаем это через сайт и сохраняем изменения (коммит "translate comments in hello_world.cpp").
  
  <br>5. Убедитесь, что в pull-request появились конфликты.<br>
  [Конфликты в pull-request'е](https://github.com/lockeystorm/lab02_hw/blob/master/check%20pt.%20III%20%235.png)
  
  <br>6. Для этого локально выполните *pull + rebase* (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты.**
  ```
  $ git pull --rebase origin master
  remote: Enumerating objects: 5, done.
  remote: Counting objects: 100% (5/5), done.
  remote: Compressing objects: 100% (3/3), done.
  remote: Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
  Unpacking objects: 100% (3/3), 1.03 KiB | 1.03 MiB/s, done.
  From https://github.com/lockeystorm/lab02_hw
   * branch            master     -> FETCH_HEAD
     eddd190..2f50f9c  master     -> origin/master
  Auto-merging hello_world.cpp
  CONFLICT (content): Merge conflict in hello_world.cpp
  error: could not apply 7ac9995... change codestyle of hello_world.cpp
  hint: Resolve all conflicts manually, mark them as resolved with
  hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
  hint: You can instead skip this commit: run "git rebase --skip".
  hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
  hint: Disable this message with "git config advice.mergeConflict false"
  Could not apply 7ac9995... change codestyle of hello_world.cpp
  ```
  
  С помощью `git pull --rebase` убедимся в наличии конфликта (CONFLICT (content): Merge conflict in hello_world.cpp) и исправим его, изменив файл через текстовый редактор.
  
  ```
  $ git add hello_world.cpp
  $ git rebase --continue
  [detached HEAD 91d6feb] change codestyle and translate comments of hello_world.cpp
   1 file changed, 8 insertions(+), 6 deletions(-)
  Successfully rebased and updated refs/heads/patch2.
  ```
  Зафиксируем изменения и продолжим rebase.
  
  <br>7. Сделайте *force push* в ветку `patch2`.
  ```
  $ git push --force-with-lease origin patch2
  Enumerating objects: 5, done.
  Counting objects: 100% (5/5), done.
  Compressing objects: 100% (3/3), done.
  Writing objects: 100% (3/3), 373 bytes | 373.00 KiB/s, done.
  Total 3 (delta 2), reused 0 (delta 0), pack-reused 0 (from 0)
  remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
  To https://github.com/lockeystorm/lab02_hw.git
   + 7ac9995...91d6feb patch2 -> patch2 (forced update)
  ```
  `--force-with-lease` - перед перезаписью удаленной ветки Git проверяет, что ее текущее состояние совпадает с ее локальной копией, если обновить ветку на сервере после последнего git pull, push отклонится с ошибкой, если ветка не менялась - сработает как обычный `--force`.
  
  <br>8. Убедитесь, что в pull-request пропали конфликты.<br>
  [Конфликтов нет, можно выполнять слияние](https://github.com/lockeystorm/lab02_hw/blob/master/PR%20without%20conflicts%20pt.%20III%20%238.png)
  
  <br>9. Вмержите pull-request `patch2 -> master`.<br>
  Слияние выполняется через GitHub.com так же, как и во второй части.
  </p>
</details>

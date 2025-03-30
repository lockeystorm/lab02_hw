## Homework for Lab02

<details>
  <summary>Part I</summary>
  <p>
  1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
  2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдущем шаге.
  ```
  $ git init
  $ git remote add origin https://github.com/lockeystorm/lab02_hw.git
  $ git pull origin master
  $ touch README.md && git add README.md
  $ git commit -m "first commit"
  $ git push -u origin master
  ```
  
  3. Создайте файл `hello_world.cpp` в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу Hello world на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку `using namespace std;`.
  ```
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
  
  4. Добавьте этот файл в локальную копию репозитория.
  ```
  $ git add hello_world.cpp
  ```

  5. Закоммитьте изменения с осмысленным сообщением.
  ```
  $ git commit -m "added hello_world.cpp bad codestyle"
  [master d6e3abc] added hello_world.cpp bad codestyle
   1 file changed, 8 insertions(+)
   create mode 100644 hello_world.cpp
  ```

  6. Измените исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение `Hello world from @name`, где `@name` имя пользователя.
  ```
  $ vim hello_world.cpp
  ```
  
  7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно `git add`?
  ```
  $ git commit -am "changed hello_world.cpp to hello world from <username>"
  [master 9bf230b] changed hello_world.cpp to hello world from <username>
   1 file changed, 5 insertions(+), 1 deletion(-)
  ```

  8. Запушьте изменения в удалённый репозиторий.
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

  9. Проверьте, что история коммитов доступна в удалённом репозитории.
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

  </p>
</details>

<details>
  <summary>Part II</summary>
  <p>
  1. В локальной копии репозитория создайте локальную ветку `patch1`.
  ```
  $ git checkout -b patch1
  Switched to a new branch 'patch1'
  ```
    
  2. Внесите изменения в ветке `patch1` по исправлению кода и избавления от `using namespace std;`.
  ```
  $ vim hello_world.cpp
  ```
  
  3. commit, push локальную ветку в удалённый репозиторий.
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

  4. Проверьте, что ветка `patch1` доступна в удалённом репозитории.
  ```
  $ git ls-remote origin patch1
  77dc79360a7aef7c6bfcb4783e59d20d0fb66376	refs/heads/patch1
  ```

  git ls-remote — показывает информацию о ссылках (ветках, тегах) в удалённом репозитории
  origin — имя удалённого репозитория
  Если ветки нет, вывод будет пустым.
  
  5. Создайте pull-request `patch1 -> master`.
  base: master <- compare:patch1  Able to merge. These branches can be automatically merged.
  
  6. В локальной копии в ветке `patch1` добавьте в исходный код комментарии.
  ```
  $ vim hello_world.cpp
  ```
  
  7. commit, push.
  ```
  $ git commit -am "added comments to hello_world.cpp"
  $ git push
  ```

  8. Проверьте, что новые изменения есть в созданном на шаге 5 pull-request
  
  9. В удалённый репозитории выполните слияние PR `patch1 -> master` и удалите ветку `patch1` в удаленном репозитории.
  
  10. Локально выполните pull.
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
  11. С помощью команды git log просмотрите историю в локальной версии ветки master.
  ```
  $ git log
  ```
  <details>
    <summary>Вывод истории коммитов:</summary>
    <p>
  ```
  commit eddd190df6ec2e325fa36cd7b57020940116dd4f (HEAD -> master, origin/master)
  Merge: 9bf230b 9f34459
  Author: lockeystorm <159271972+lockeystorm@users.noreply.github.com>
  Date:   Sun Mar 30 18:05:08 2025 +0300
  
      Merge pull request #1 from lockeystorm/patch1
      
      pull request patch1 with 2 commits to master
  
  commit 9f344595daee66eeb5721867e21d79cf3e08bca8 (origin/patch1, patch1)
  Author: lockeystorm <wallie4@ya.ru>
  Date:   Sat Mar 29 00:18:43 2025 +0300
  
      added comments to hello_world.cpp
  
  commit 77dc79360a7aef7c6bfcb4783e59d20d0fb66376
  Author: lockeystorm <wallie4@ya.ru>
  Date:   Fri Mar 28 23:43:32 2025 +0300
  
      removed 'using namespace std'
  
  commit 9bf230b7f8c10ecc70323e9563192286448df229
  Author: lockeystorm <wallie4@ya.ru>
  Date:   Fri Mar 28 23:03:43 2025 +0300
  
      changed hello_world.cpp to hello world from <username>
  
  commit f12035e0aadfe2e7211a5d603e7115d49b1347d5
  Author: lockeystorm <159271972+lockeystorm@users.noreply.github.com>
  Date:   Fri Mar 28 22:51:05 2025 +0300
  
      Update minor mistake in hello_world.cpp
  
  commit d6e3abccbbad01a988a4a98a795c7a904e753c20
  Author: lockeystorm <wallie4@ya.ru>
  Date:   Fri Mar 28 21:59:05 2025 +0300
  
      added hello_world.cpp bad codestyle
  
  commit 2f6e32cc35fd045cc8b0d7c3cd063741995ef707
  Author: lockeystorm <wallie4@ya.ru>
  Date:   Fri Mar 28 21:17:13 2025 +0300
  
      first commit
  
  commit 1f81043d57d94502b3a9602393301fa1ce496b01
  Author: lockeystorm <159271972+lockeystorm@users.noreply.github.com>
  Date:   Fri Mar 28 16:56:07 2025 +0300
  
      Initial commit
  ```
    </p>
    </details>
  12. Удалите локальную ветку `patch1`.
  ```
  $ git branch -d patch1
  Deleted branch patch1 (was 9f34459).
  
  $ git fetch -p
  From https://github.com/lockeystorm/lab02_hw
   - [deleted]         (none)     -> origin/patch1
  ```
  </p>
</details>

<details>
  <summary>Part III</summary>
  <p>
  1. Создайте новую локальную ветку `patch2`.
  ```
  $ git checkout -b patch2
  Switched to a new branch 'patch2'
  ```

  2. Измените *code style* с помощью утилиты *clang-format*. Например, используя опцию `-style=Mozilla`.
  ```
  $ clang-format -i -style=Mozilla hello_world.cpp
  ```
  
  3. commit, push, создайте pull-request `patch2 -> master`.
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
  
  4. В ветке `master` в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
  делается через сайт
  
  5. Убедитесь, что в pull-request появились конфликты.
  
  6. Для этого локально выполните *pull + rebase* (точную последовательность команд, следует узнать самостоятельно). **Исправьте конфликты.**
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
  
  $ vim hello_world.cpp
  
  $ git add hello_world.cpp
  $ git rebase --continue
  [detached HEAD 91d6feb] change codestyle and translate comments of hello_world.cpp
   1 file changed, 8 insertions(+), 6 deletions(-)
  Successfully rebased and updated refs/heads/patch2.
  ```
  
  7. Сделайте *force push* в ветку `patch2`.
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
  
  8. Убедитесь, что в pull-request пропали конфликты.
  
  9. Вмержите pull-request `patch2 -> master`.
  
  </p>
</details>

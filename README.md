# 📘 Шпаргалка по Git-командам

> **Git** — распределённая система управления версиями. Эта шпаргалка содержит основные команды для повседневной работы.

---

## 📑 Содержание

1. [Настройка и конфигурация](#настройка-и-конфигурация)
2. [Инициализация и клонирование](#инициализация-и-клонирование)
3. [Базовая работа с коммитами](#базовая-работа-с-коммитами)
4. [Ветвление и слияние](#ветвление-и-слияние)
5. [Просмотр истории и статуса](#просмотр-истории-и-статуса)
6. [Отмена изменений](#отмена-изменений)
7. [Удалённые репозитории](#удалённые-репозитории)
8. [Теги и релизы](#теги-и-релизы)
9. [Продвинутые техники](#продвинутые-техники)
10. [Полезные советы](#полезные-советы)

---

## Настройка и конфигурация

### Глобальные настройки

```bash
# Установить имя пользователя
git config --global user.name "Ваше Имя"

# Установить email
git config --global user.email "your.email@example.com"

# Установить редактор по умолчанию
git config --global core.editor "nano"

# Включить подсветку синтаксиса
git config --global color.ui auto
```

### Просмотр конфигурации

| Команда | Описание |
|---------|----------|
| `git config --list` | Показать все настройки |
| `git config user.name` | Показать имя пользователя |
| `git config --global --edit` | Открыть глобальный конфиг в редакторе |

---

## Инициализация и клонирование

### Создание репозитория

```bash
# Инициализировать новый репозиторий в текущей директории
git init

# Инициализировать с указанием имени ветки по умолчанию
git init -b main
```

### Клонирование

```bash
# Клонировать удалённый репозиторий
git clone https://github.com/username/repo.git

# Клонировать в конкретную директорию
git clone https://github.com/username/repo.git my-folder

# Клонировать конкретную ветку
git clone -b develop https://github.com/username/repo.git
```

---

## Базовая работа с коммитами

### Добавление файлов

```bash
# Добавить конкретный файл
git add file.txt

# Добавить все изменённые файлы
git add .

# Добавить все файлы, включая новые
git add -A

# Интерактивное добавление
git add -p
```

### Создание коммитов

```bash
# Создать коммит с сообщением
git commit -m "Описание изменений"

# Создать коммит, открыв редактор
git commit

# Изменить последний коммит
git commit --amend -m "Новое описание"

# Добавить все файлы и закоммитить одной командой
git commit -am "Описание"
```

> ⚠️ **Важно:** Всегда пишите осмысленные сообщения коммитов!

---

## Ветвление и слияние

### Работа с ветками

```bash
# Показать все ветки
git branch

# Показать все ветки, включая удалённые
git branch -a

# Создать новую ветку
git branch feature-name

# Создать и переключиться на новую ветку
git checkout -b feature-name

# Современный способ (Git 2.23+)
git switch -c feature-name

# Переключиться на существующую ветку
git checkout main
git switch main

# Удалить ветку
git branch -d feature-name

# Удалить ветку принудительно
git branch -D feature-name
```

### Слияние веток

```bash
# Переключиться на целевую ветку
git checkout main

# Влить изменения из другой ветки
git merge feature-name

# Отменить слияние при конфликте
git merge --abort
```

### Rebase

```bash
# Перебазировать текущую ветку на main
git rebase main

# Интерактивный rebase (последние 3 коммита)
git rebase -i HEAD~3
```

---

## Просмотр истории и статуса

### Статус репозитория

```bash
# Показать статус файлов
git status

# Краткий статус
git status -s
```

### История коммитов

```bash
# Показать историю коммитов
git log

# Краткий формат (одна строка на коммит)
git log --oneline

# С графиком ветвления
git log --oneline --graph --all

# Показать последние N коммитов
git log -5

# С фильтром по автору
git log --author="Ваше Имя"

# С фильтром по дате
git log --since="2 weeks ago"
git log --until="2024-01-01"
```

### Различия между версиями

```bash
# Показать изменения в рабочем каталоге
git diff

# Показать изменения между коммитами
git diff commit1 commit2

# Показать изменения конкретного файла
git diff file.txt

# Показать изменения в staged файлах
git diff --staged
```

---

## Отмена изменений

### Отмена изменений в файлах

| Ситуация | Команда |
|----------|---------|
| Отменить изменения в файле (до `git add`) | `git checkout -- file.txt` |
| Отменить изменения в файле (после `git add`) | `git restore file.txt` |
| Убрать файл из staged | `git reset HEAD file.txt` |
| Удалить файл из репозитория | `git rm file.txt` |

### Отмена коммитов

```bash
# Отменить последний коммит, сохранив изменения
git reset --soft HEAD~1

# Отменить коммит и изменения в staged
git reset --mixed HEAD~1

# Полностью отменить коммит и изменения
git reset --hard HEAD~1

# ⚠️ Опасно! Откатиться к конкретному коммиту
git reset --hard <commit-hash>
```

### Revert (безопасная отмена)

```bash
# Отменить коммит, создав новый обратный коммит
git revert <commit-hash>

# Отменить несколько коммитов
git revert HEAD~2..HEAD
```

---

## Удалённые репозитории

### Работа с remote

```bash
# Показать удалённые репозитории
git remote -v

# Добавить удалённый репозиторий
git remote add origin https://github.com/user/repo.git

# Удалить remote
git remote remove origin

# Переименовать remote
git remote rename origin upstream
```

### Синхронизация с удалённым репозиторием

```bash
# Получить изменения с remote (без слияния)
git fetch origin

# Получить и влить изменения
git pull origin main

# Отправить изменения на remote
git push origin main

# Отправить все ветки
git push --all origin

# Отправить теги
git push --tags

# Принудительная отправка (⚠️ опасно)
git push --force
```

---

## Теги и релизы

```bash
# Показать все теги
git tag

# Создать легковесный тег
git tag v1.0.0

# Создать аннотированный тег
git tag -a v1.0.0 -m "Версия 1.0.0"

# Отправить тег на remote
git push origin v1.0.0

# Отправить все теги
git push --tags

# Удалить тег локально
git tag -d v1.0.0

# Удалить тег на remote
git push --delete origin v1.0.0
```

---

## Продвинутые техники

### Stash (временное сохранение)

```bash
# Сохранить изменения во stash
git stash

# Сохранить с сообщением
git stash save "WIP: feature in progress"

# Показать список stash
git stash list

# Применить последний stash
git stash apply

# Применить и удалить
git stash pop

# Удалить stash
git stash drop

# Очистить все stash
git stash clear
```

### Cherry-pick

```bash
# Взять конкретный коммит из другой ветки
git cherry-pick <commit-hash>

# Взять несколько коммитов
git cherry-pick commit1^..commit2
```

### Bisect (поиск бага)

```bash
# Запустить бинарный поиск
git bisect start

# Пометить текущий коммит как плохой
git bisect bad

# Пометить коммит как хороший
git bisect good <commit-hash>

# Закончить поиск
git bisect reset
```

### Submodules

```bash
# Добавить подмодуль
git submodule add <repository-url> <path>

# Инициализировать подмодули
git submodule init

# Обновить подмодули
git submodule update
```

---

## Полезные советы

### 🔹 Алиасы для ускорения работы

Добавьте в `~/.gitconfig`:

```ini
[alias]
    co = checkout
    br = branch
    ci = commit
    st = status
    lg = log --oneline --graph --all
    last = log -1 HEAD
    unstage = reset HEAD --
```

Использование:

```bash
git st      # вместо git status
git lg      # вместо git log --oneline --graph --all
```

### 🔹 .gitignore

Пример файла `.gitignore`:

```gitignore
# Игнорировать файлы
*.log
*.tmp
node_modules/
__pycache__/
.env
.DS_Store

# Но не игнорировать конкретный файл
!important.log
```

---

*Последнее обновление: Сентябрь 2024*

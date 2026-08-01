# Git Quick Guide

Git is a version control system. It records changes to files, lets you return to earlier versions, and makes it easier for several people to work on the same project.

## Start a new project

```bash
mkdir my-project
cd my-project
git init
git branch -M main
```

Set your identity once (used in commits):

```bash
git config --global user.name "Your Name"
git config --global user.email "you@example.com"
```

## Save changes

Check what changed:

```bash
git status
```

Add one file, then create a commit:

```bash
git add README.md
git commit -m "Add project README"
```

Add all changed files:

```bash
git add .
git commit -m "Describe the change"
```

View history:

```bash
git log --oneline
```

## Clone and passively keep a repository updated

Clone a remote repository once:

```bash
git clone https://example.com/owner/repository.git
cd repository
```

Later, enter its directory and download/apply the newest changes:

```bash
git pull
```

`git pull` normally fetches changes from the remote and merges them into your current branch.

## Update while discarding local changes

First inspect what would be lost:

```bash
git status
```

Discard only uncommitted edits to tracked files, then update:

```bash
git restore .
git pull
```

Make the current branch exactly match the remote branch (this also discards local commits):

```bash
git fetch origin
git reset --hard origin/main
```

Replace `main` with the appropriate branch name when needed. `git reset --hard` permanently removes uncommitted changes and local commits from the current branch, so use it only when that is intended.

## Branches

Create and switch to a branch:

```bash
git switch -c feature/my-change
```

Switch back:

```bash
git switch main
```

## Send commits to a remote repository

Add a remote for a new local project:

```bash
git remote add origin https://example.com/owner/repository.git
git push -u origin main
```

For later commits:

```bash
git push
```

# Push this to a private GitHub repo

This folder is already a git repository with one commit. To publish it privately on
your account (`joachimth`), from inside this folder run **one** of:

```bash
# with the GitHub CLI (easiest):
gh repo create joachimth/edc16u1-octavia-reconstruction --private --source=. --remote=origin --push

# or with plain git, after creating an empty private repo on github.com:
git remote add origin https://github.com/joachimth/edc16u1-octavia-reconstruction.git
git branch -M main
git push -u origin main
```

That's it — the history and all files upload as-is. (This session can only read public
repos anonymously; it cannot create or push to your account, which is why it's handed
to you ready to push rather than published directly.)

#!/bin/sh

export EDITOR=vin
git config --global user.email ab25cq@icloud.com
git config --global user.name ab25cq

rm -rf build

git add .
git commit -m "first commit"
git branch -M main
git remote add origin https://github.com/ab25cq/minux2.git
git push -u origin main

# Bejeweled2-Deluxe-Cheat-Tool

Bejeweled2 Deluxe 製作遊戲修改器教學

![](http://i.imgur.com/fztYy0z.png)



- 修改的遊戲：Bejeweled 2 Deluxe 1.0
- 工具：Cheat Engine 6.4



![](http://i.imgur.com/eLfIadg.png)


## Step1 ##
使用 Cheat Engine 6.4 選擇目標遊戲 (Select a process to open)
![](http://i.imgur.com/AlVKKtk.png)


## Step2 ##

首先試著找到位址
![](http://i.imgur.com/uElPBv1.png)

改變一下分數，會發現有兩個Address是我們要的

![](http://i.imgur.com/89ZLp2J.png)

雙擊加入(我認定你知道怎麼找到位址了)


## Step3 ##

![](http://i.imgur.com/F8lNKKj.png)


當你已經找到位址時，在表格區的位址按右鍵並選擇
"找出寫入此位址的位址(Find out what writes to this address)"

![](http://i.imgur.com/nioH9rk.png)


按More information，出現一個新的視窗

![](http://i.imgur.com/hsoEiP2.png)

裡面有一段話，寫說需要被找到pointer位址的值可能是061BA9F0 (記住此值)

還有一個重點[ebx+00015DF0]

offset = 00015DF0 (記住此值)


回到cheat engine 找這個值。
把Hex打勾(Hex打勾代表用16進位制)，在value:裡面輸入值61BA9F0（前面0不用打），按下First Scan。

![](http://i.imgur.com/8aSA8CQ.png)

成功的話會找到一條Address是綠色的，

恭喜你找到pointer位址：0059ACB8。



## Step4 ##
驗證一下

pointer位址：0059ACB8。
offset = 00015DF0 (記住此值)

- 按Add address manually(手動加入位址)
- Pointer打勾
- 先輸入offset
- 指針的位址0059ACB8 輸入再最下面一格
- 會看到算出的位址 = 061D07E0 和 搜尋到的位址一樣
- 這樣遊戲重開位址改變還是能修改成功！

![](http://i.imgur.com/Qyl6SMk.png)

## Step5 ##
source code 裡加入address和offset
![](http://i.imgur.com/koUtG7t.png)


![](http://i.imgur.com/3juYHce.png)

[點此下載遊戲修改器](https://drive.google.com/open?id=0BzUSEyOU2e3zQ000VW45QnIzcXc)


## 參考文獻 ##
- http://forum.gamer.com.tw/C.php?bsn=02450&snA=674
- http://blog.yam.com/celearning/article/35309209
- http://www.bcwhy.com/thread-21055-1-1.html
- http://bejeweled-2-deluxe.soft32.com/

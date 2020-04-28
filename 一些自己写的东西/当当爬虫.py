import re
import requests

def request(url):
    try:
        response=requests.get(url)
        if response.status_code==200:
            return response.text
    except requests.RequestException:
        print('No!!!')
        return None

def work(html):
    pattern=re.compile('<li>.*?list_num.*?(\d+).</div>.*?<img src="(.*?)".*?class="name".*?title="(.*?)">.*?class="star">.*?class="tuijian">(.*?)</span>.*?class="publisher_info">.*?target="_blank">(.*?)</a>.*?class="biaosheng">.*?<span>(.*?)</span></div>.*?<p><span\sclass="price_n">&yen;(.*?)</span>.*?</li>',re.S)
    anss=re.findall(pattern,html)
    for ans in anss:
        yield{
            '排名': ans[0],
           'iamge': ans[1],
           '标题': ans[2],
           'recommend': ans[3],
           'author': ans[4],
           'times': ans[5],
           'price': ans[6]
        }

def main(page):
    url='http://bang.dangdang.com/books/fivestars/01.00.00.00.00.00-recent30-0-0-1-'+str(page)
    html=request(url)
    print('get')
    anss=work(html)
    for ans in anss:
        print(ans)
    print('end')

print('start')
main(1)
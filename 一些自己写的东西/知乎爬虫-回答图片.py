import os
import time
import requests
from  selenium import webdriver
from bs4 import BeautifulSoup
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities


options = webdriver.ChromeOptions()
options.add_argument('user-agent="Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_4) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.1 Safari/605.1.15"')
options.add_argument('--headless')#不显示窗口
prefs = {"profile.managed_default_content_settings.images": 2}
options.add_experimental_option("prefs", prefs)#不加载图片
browser=webdriver.Chrome(chrome_options=options)
WAIT = WebDriverWait(browser, 10)
browser.set_window_size(1400, 900)

j=1
headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_4) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.1 Safari/605.1.15'}

def download_Pic(image_list):
    global j
    for item in image_list:
        filename = '%s.jpg' % (str(j))
        print('downloading....NO.%s' % (str(j)))
        with open(filename, 'wb') as f:
            img = requests.get(item, headers=headers).content
            f.write(img)
        j += 1

def download(url):
    browser.get(url)
    cnt=0
    while True:
        cnt=0
        html = browser.page_source
        soup = BeautifulSoup(html, 'lxml')
        image_list=[]
        list=soup.find_all(class_='List-item')
        for item in list:
            try:
                list2 = item.find(class_='RichText ztext CopyrightRichText-richText').find_all('figure')
                for item2 in list2:
                    try:
                        img_url = item2.find('img').get('src')
                        if img_url not in image_list:
                            image_list.append(img_url)
                            cnt=cnt+1
                    except:
                        a=1
            except:
                a=1
        browser.execute_script('window.scrollTo(0,10000000)')
        if cnt>=10:
            break
    download_Pic(image_list)
    print('total:%d'%(cnt))

if __name__ == '__main__':
    try:
        os.mkdir("file") 
        os.chdir('file')
        for i in range(1,2):
            download('https://www.zhihu.com/question/384408291')
    finally:
        browser.close()

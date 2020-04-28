from  selenium import webdriver
from bs4 import BeautifulSoup
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities
import xlwt
####################
dcap = dict(DesiredCapabilities.PHANTOMJS)
dcap["phantomjs.page.settings.userAgent"] = ("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_4) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.1 Safari/605.1.15") #设置user-agent请求头
dcap["phantomjs.page.settings.loadImages"] = False #禁止加载图片
browser=webdriver.PhantomJS(desired_capabilities=dcap)
WAIT = WebDriverWait(browser, 10)
browser.set_window_size(1400, 900)
###################
#options = webdriver.ChromeOptions()
#options.add_argument('user-agent="Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Safari/537.36"')
#prefs = {"profile.managed_default_content_settings.images": 2}
#options.add_experimental_option("prefs", prefs)#不加载图片
#browser=webdriver.Chrome(chrome_options=options)
#WAIT = WebDriverWait(browser, 10)
#browser.set_window_size(1400, 900)
#####################
n=1
ok=1
fail=0

book = xlwt.Workbook(encoding='utf-8', style_compression=0)
sheet = book.add_sheet('1', cell_overwrite_ok=True)
sheet.write(0, 0, '名称')
sheet.write(0, 1, '地址')

def save(soup):
    list=soup.find(class_='zu-main-content-inner').find_all(class_='zm-item')
    for item in list:
        try:
            item_title = item.find(class_='zm-item-title').find('a').get_text()
            item_link = item.find(class_='zm-item-title').find('a').get('href')
            if '.com' not in item_link:
                item_link = 'https://www.zhihu.com'+ item_link
            print('爬取：' + item_title)
            global n
            sheet.write(n, 0, item_title)
            sheet.write(n, 1, item_link)
        except :
            global fail
            fail=fail+1
        n = n + 1

def get_source():
    html = browser.page_source
    soup = BeautifulSoup(html, 'lxml')
    save(soup)

def search():
    print('start')
    for i in range(284,566):
        browser.get("https://www.zhihu.com/collection/86696007?ssr_src=heifetz&page="+str(i))
        get_source()
        print('pages: %d ok'%(i))
def main():
    try:
        search()
    finally:
        print('end failed:%d'%(fail))
        browser.close()

main()
book.save('2.xls')

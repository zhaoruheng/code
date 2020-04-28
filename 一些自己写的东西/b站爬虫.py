from  selenium import webdriver
from bs4 import BeautifulSoup
from selenium.common.exceptions import TimeoutException
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import xlwt

options = webdriver.ChromeOptions()
options.add_argument('user-agent="Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.149 Safari/537.36"')
browser=webdriver.Chrome(chrome_options=options)
WAIT = WebDriverWait(browser, 10)
browser.set_window_size(1400, 900)
n=1
ok=1

book = xlwt.Workbook(encoding='utf-8', style_compression=0)
sheet = book.add_sheet('1', cell_overwrite_ok=True)
sheet.write(0, 0, '名称')
sheet.write(0, 1, '地址')
sheet.write(0, 2, '描述')
sheet.write(0, 3, '观看次数')
sheet.write(0, 4, '弹幕数')
sheet.write(0, 5, '发布时间')

def save(soup):
    list=soup.find(class_='video-list clearfix').find_all(class_='video-item matrix')
    for item in list:
        item_title = item.find('a').get('title')
        item_link = item.find('a').get('href')
        item_dec = item.find(class_='des hide').text
        item_view = item.find(class_='so-icon watch-num').text
        item_biubiu = item.find(class_='so-icon hide').text
        item_date = item.find(class_='so-icon time').text
        print('爬取：' + item_title)
        global n
        sheet.write(n, 0, item_title)
        sheet.write(n, 1, item_link)
        sheet.write(n, 2, item_dec)
        sheet.write(n, 3, item_view)
        sheet.write(n, 4, item_biubiu)
        sheet.write(n, 5, item_date)
        n = n + 1

def get_source():
    WAIT.until(EC.presence_of_element_located(
        (By.CSS_SELECTOR, '#all-list > div.flow-loader > div.filter-wrap')))
    html = browser.page_source
    soup = BeautifulSoup(html, 'lxml')
    print('ok')
    save(soup)

def search():
#    try:
        print('start')
        browser.get("https://www.bilibili.com/")
        input = WAIT.until(EC.presence_of_element_located((By.CSS_SELECTOR, "#nav_searchform > input")))
        submit = WAIT.until(EC.element_to_be_clickable(
            (By.XPATH, '/html/body/div[2]/div/div[1]/div[1]/div/div[2]/div/form/div/button')))
        input.send_keys('墨阴白晴')
        submit.click()

        allh=browser.window_handles
        browser.switch_to_window(allh[1])
        get_source()
#        total=WAIT.until(EC.presence_of_element_located((By.CSS_SELECTOR,
#                                                           "#all-list > div.flow-loader > div.page-wrap > div > ul > li.page-item.last > button")))
#        return int(total.text)
#    except TimeoutException:
#        print('Timeout')

def next(page):
    try:
        print('next page')
        next_btn = WAIT.until(EC.element_to_be_clickable((By.CSS_SELECTOR,
                                                          '#all-list > div.flow-loader > div.page-wrap > div > ul > li.page-item.next > button')))
        next_btn.click()
        now=WAIT.until(EC.element_to_be_clickable((By.CSS_SELECTOR,
                                                          '#all-list > div.flow-loader > div.page-wrap > div > ul > li.page-item.active > button')))
        global ok
        if int(now.text) != page:
            ok=0
        WAIT.until(EC.text_to_be_present_in_element((By.CSS_SELECTOR,
                                                     '#all-list > div.flow-loader > div.page-wrap > div > ul > li.page-item.active > button'),
                                                    str(page)))
        get_source()
    except TimeoutException:
        ok=0

def main():
    try:
        search()
        print("search success")
        i=2
        while ok:
            print("searching %d"%(i))
            next(i)
            i+=1
    finally:
        print('end')
        browser.close()

main()
book.save('1.xls')

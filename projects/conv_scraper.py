# importing packages
from selenium import webdriver
import json
#initialization  of variables
x = 1
stock_input = input("enter a stock: ")
#pull starting packages 
driver = webdriver.Chrome("/Users/mahip/Desktop/coding/AI/stockpredictionai/chromedriver")
driver.get("https://finance.yahoo.com/quote/"+stock_input+"/community/")

# expand the page for more comments
driver.find_element_by_xpath("""//*[@id="canvass-0-CanvassApplet"]/div/button""").click()

# loop 50 times and store comment in a json file
while x != 51:
    comments = driver.find_element_by_xpath("""//*[@id="canvass-0-CanvassApplet"]/div/ul/li["""+str(x)+"""]""")
    with open(stock_input + "_conv.json", "a") as out:
        json.dump(  # dumps data into json
            comments.text,  # data to dump
            out,
            indent=2,  # indents it to be pretty
            ensure_ascii=False,  # makes sure any non-ascii characters are also dumped, by default not
        )
        out.write('\n')
    x +=1
    # expand the page for more comments
    if (x < 10):
         driver.find_element_by_xpath("""//*[@id="canvass-0-CanvassApplet"]/div/button""").click()
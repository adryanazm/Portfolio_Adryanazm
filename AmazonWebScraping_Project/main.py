from bs4 import BeautifulSoup
import requests
import time
import datetime

import smtplib

# connect to website

URL = 'https://www.amazon.com/Dreamus-ZEROBASEONE-MELTING-POINT-Album/dp/B0CKL8W12F/ref=sr_1_1?crid=2DTGZ9TGD1RVO&dib=eyJ2IjoiMSJ9.k87hdDGCcWEBBgFf6ZRHzRuaz7ouh398yOo7K2bYxgtVB0NEaA0-dsvuUippSVfNqH8oTtqJzvkBuK5CEl1tZKt48QJbaMOmAgENutQ-UPgTNSfskv9NgZcSGl6K5M9af6HBD8lYAFdBny3mU-e-0gPhPWllnkCRwHyAl-zDErtIaSRgKjJfCgFxB-AMBqNP9Crl16o6zC8PK2gr9oVCodW2Dm4wEcnBRa2oiiq0q-uxZ9FJzCo_3Sd2MhQgZclWYz8AqkfGJVJOg1LIC5pmNjUapVPvECtZgnO1IKEoD0E.ayemGnvCepusPmlQNOdYTmY0Sya-Gs5RxH2vAQp_QBo&dib_tag=se&keywords=zerobase+one&qid=1729220706&sprefix=zerobaseon%2Caps%2C350&sr=8-1'
page = requests.get(URL)

soup1 = BeautifulSoup(page.content, "lxml")

soup2 = BeautifulSoup(soup1.prettify(), "lxml")

title = soup2.find(id='productTitle').get_text()
# clean up data
title = title.strip()

brand = soup2.find(id='bylineInfo').get_text()
# clean up data
brand = brand.strip()

print(title)
print(brand)

# Create a Timestamp for your output to track when data was collected
today = datetime.date.today()


print(today)

# create csv and write headers and data into file
import csv

header = ["Title", "Brand", "Date"]
data = [title, brand, today]

with open('ZB1AlbumScraper.csv', 'w', newline='', encoding='UTF8') as f:
    writer = csv.writer(f)
    writer.writerow(header)
    writer.writerow(data)
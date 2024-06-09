import webbrowser

# Function to open a link
def open_link(url):
    # Open URL in a new tab, if a browser window is already open.
    webbrowser.open_new_tab(url)

# URL to be opened
url = "http://www.example.com"

# Call the function with the URL
open_link(url)
    
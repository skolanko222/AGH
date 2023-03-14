# ex. og=f setup.py file with a requirements.txt containing required modules

import setuptools

with open("requirements.txt", "r") as req_file:
   requirements = req_file.readlines()

setuptools.setup(
    name = "testpackage",
    version = "1.0",
    author = "<Szymon Kolanko>",
    author_email = "skolanko@student.agh.edu.pl",
    description = "Example package structure",
    packages = setuptools.find_packages(),
    install_requires = [req for req in requirements if req[:2] != "# "]
)
from ctypes import *

def readFileContents(filename):
    f = open(filename+".txt", "r")
    content = f.read()
    f.close()
    return content
def writeNewFile(filename):
    f = open(filename+"_compressed.txt", "w+")
    f.write(content)
    f.close()
if __name__=="__main__":
    filename = "text"
    content = readFileContents(filename)
    my_P_to_C = cdll.LoadLibrary(r"D:\VisualStudio\huffman_dll\huffmanEncode\x64\Debug\huffmanEncode.dll")
    print(my_P_to_C.testvect(c_wchar('a')))
    status = my_P_to_C.huffman(c_wchar_p(content), c_uint(len(content)))
    print(status)

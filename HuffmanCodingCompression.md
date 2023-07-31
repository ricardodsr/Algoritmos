# Huffman Coding Compression

A compressão de Huffman é um algoritmo utilizado para compactar dados, reduzindo o tamanho de arquivos sem perda de informação. Ele é baseado na construção de códigos de comprimento variável, chamados de códigos de Huffman, que atribuem sequências de bits mais curtas para os caracteres ou símbolos mais frequentes e sequências de bits mais longas para os menos frequentes.

# Processo

1- Frequência de ocorrência: O algoritmo analisa os dados de entrada (por exemplo, um texto) e calcula a frequência de ocorrência de cada caractere ou símbolo presente. Isso pode ser feito por meio de uma contagem dos caracteres ou usando uma tabela de frequências pré-calculada.

2- Construção da Árvore de Huffman: Com base nas frequências de ocorrência, o algoritmo constrói uma árvore binária especial chamada Árvore de Huffman. Essa árvore é construída de baixo para cima, começando pelos caracteres menos frequentes e terminando nos caracteres mais frequentes. Os nós internos da árvore representam a soma das frequências dos caracteres filhos.

3- Atribuição de códigos: A partir da Árvore de Huffman, atribui-se um código binário único para cada caractere ou símbolo. O código é obtido seguindo o caminho da raiz até o nó correspondente ao caractere desejado. Atribui-se 0 para o caminho à esquerda e 1 para o caminho à direita.

4- Compressão: Os dados de entrada são substituídos pelos códigos de Huffman correspondentes a cada caractere. Essa substituição reduz o tamanho do arquivo original, já que os códigos de Huffman são otimizados para que os caracteres mais frequentes sejam representados por sequências de bits mais curtas.

5- Descompressão: Para descompactar os dados, é necessário ter acesso à Árvore de Huffman original. Os códigos de Huffman são lidos sequencialmente do arquivo comprimido e a cada código lido, a árvore é percorrida a partir da raiz até a folha correspondente. O caractere ou símbolo correspondente ao código é recuperado e adicionado ao arquivo descomprimido.

# Codigo Fonte em Python

    import heapq
    from heapq import heappop, heappush


    def isLeaf(root):
        return root.left is None and root.right is None


    # A Tree node
    class Node:
        def __init__(self, ch, freq, left=None, right=None):
            self.ch = ch
            self.freq = freq
            self.left = left
            self.right = right

        # Override the `__lt__()` function to make `Node` class work with priority queue
        # such that the highest priority item has the lowest frequency
        def __lt__(self, other):
            return self.freq < other.freq


    # Traverse the Huffman Tree and store Huffman Codes in a dictionary
    def encode(root, s, huffman_code):

        if root is None:
            return

        # found a leaf node
        if isLeaf(root):
            huffman_code[root.ch] = s if len(s) > 0 else '1'

        encode(root.left, s + '0', huffman_code)
        encode(root.right, s + '1', huffman_code)


    # Traverse the Huffman Tree and decode the encoded string
    def decode(root, index, s):

        if root is None:
            return index

        # found a leaf node
        if isLeaf(root):
            print(root.ch, end='')
            return index

        index = index + 1
        root = root.left if s[index] == '0' else root.right
        return decode(root, index, s)


    # Builds Huffman Tree and decodes the given input text
    def buildHuffmanTree(text):

        # base case: empty string
        if len(text) == 0:
            return

        # count the frequency of appearance of each character
        # and store it in a dictionary
        freq = {i: text.count(i) for i in set(text)}

        # Create a priority queue to store live nodes of the Huffman tree.
        pq = [Node(k, v) for k, v in freq.items()]
        heapq.heapify(pq)

        # do till there is more than one node in the queue
        while len(pq) != 1:

            # Remove the two nodes of the highest priority
            # (the lowest frequency) from the queue

            left = heappop(pq)
            right = heappop(pq)

            # create a new internal node with these two nodes as children and
            # with a frequency equal to the sum of the two nodes' frequencies.
            # Add the new node to the priority queue.

            total = left.freq + right.freq
            heappush(pq, Node(None, total, left, right))

        # `root` stores pointer to the root of Huffman Tree
        root = pq[0]

        # traverse the Huffman tree and store the Huffman codes in a dictionary
        huffmanCode = {}
        encode(root, '', huffmanCode)

        # print the Huffman codes
        print('Huffman Codes are:', huffmanCode)
        print('The original string is:', text)

        # print the encoded string
        s = ''
        for c in text:
            s += huffmanCode.get(c)

        print('The encoded string is:', s)
        print('The decoded string is:', end=' ')

        if isLeaf(root):
            # Special case: For input like a, aa, aaa, etc.
            while root.freq > 0:
                print(root.ch, end='')
                root.freq = root.freq - 1
        else:
            # traverse the Huffman Tree again and this time,
            # decode the encoded string
            index = -1
            while index < len(s) - 1:
                index = decode(root, index, s)


    # Huffman coding algorithm implementation in Python
    if __name__ == '__main__':

        text = 'Huffman coding is a data compression algorithm.'
        buildHuffmanTree(text)

# A compressão de Huffman é amplamente utilizada em algoritmos de compressão de dados, como em formatos de arquivo como o ZIP. Ela é eficiente para reduzir o tamanho de arquivos de texto, especialmente quando há caracteres ou símbolos com frequências de ocorrência muito discrepantes.
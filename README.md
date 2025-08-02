# 📦 Projeto: `cpp-api-template`

## 🔧 Descrição

Este projeto é um **template simples e genérico de API REST em C++**, utilizando a biblioteca [Crow](https://github.com/CrowCpp/Crow) para criação de endpoints e a [nlohmann/json](https://github.com/nlohmann/json) para manipulação de JSON. A ideia é servir como base para quem deseja integrar C++ com qualquer banco de dados de sua escolha e construir APIs leves e rápidas.

Você pode adaptar facilmente este projeto para consultar, cadastrar, editar ou remover dados em qualquer estrutura de banco (PostgreSQL, SQLite, MySQL etc).

## Funcionalidades

- Servidor HTTP básico com Crow
- Endpoint POST genérico (`/select`)
- Retorno de JSON estruturado
- Frontend simples em HTML + JavaScript para consumo do endpoint
- Totalmente adaptável a qualquer banco de dados

## 📁 Estrutura do Projeto

```
├── index.html              # Página HTML com input e fetch JS
├── main.cpp                # Código principal da API
├── README.md               # Este arquivo
```
> Obs: você pode reorganizar os arquivos conforme desejar.

## 🛠️ Tecnologias utilizadas

- C++
- [Crow](https://github.com/CrowCpp/Crow)
- [nlohmann/json](https://github.com/nlohmann/json)
- HTML + JavaScript (Frontend básico)
- Banco de dados (você escolhe!)

## Como usar

1. **Clone o repositório:**
```bash
git clone https://github.com/seu-usuario/cpp-api-template.git
cd cpp-api-template
```

2. **Instale as dependências:**
- Instale o Crow e o nlohmann/json (via vcpkg ou manualmente)
- Configure seu banco de dados se quiser usar um

3. **Compile e execute:**
   Se estiver usando g++, por exemplo:
```bash
g++ main.cpp -o server -lpqxx -lpq -std=c++20
./server
```

4. **Abra no navegador:**
```
http://localhost:8080
```

## 💡 Personalização

Você pode alterar a lógica da rota `/select` para se conectar com o banco de dados da sua preferência e executar as queries que quiser. O frontend envia um JSON com um campo `documento` (valor do input), que você pode usar como filtro para consultas, inserções ou qualquer outra operação.

## ✅ Exemplo de resposta esperada
```json
[
  {
    "id": 1,
    "titulo": "Exemplo",
    "lancamento": "2023-01-01",
    "genero": "Aventura"
  }
]

```
> Obs: os campos podem ser alterados conforme sua estrutura de dados.

## 🧠 Para que serve?

Esse projeto pode ser usado como:
- Base para APIs em C++
- Testes de integração com banco
- Estudos de JSON em C++
- Alternativa leve a frameworks como Node ou Flask para APIs simples

## 🤝 Contribuições

Sugestões, melhorias ou correções são bem-vindas! Basta abrir um Pull Request ou criar uma issue no repositório.

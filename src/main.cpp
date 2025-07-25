#include <iostream>
#include <pqxx/pqxx>
#include <crow.h>
#include <nlohmann/json.hpp>

int main() {
        crow::SimpleApp app;

    CROW_ROUTE(app, "/")([] {
        std::ifstream html("../index.html");

        if (!html.is_open()) {
            std::cerr << "[ERRO] Não achou index.html no diretório: "
                      << std::filesystem::current_path() << std::endl;
            return crow::response(404, "Arquivo index.html NÃO encontrado");
        }

        std::stringstream buffer;
        buffer << html.rdbuf();
        html.close();

        crow::response res(buffer.str());
        res.set_header("Content-Type", "text/html");
        return res;
    });

    CROW_ROUTE(app, "/select").methods(crow::HTTPMethod::POST)(
        [](const crow::request& req) {
            crow::response res;
            try {
                //faz a conexão com o banco de dados
                pqxx::connection conn("dbname=nomedobanco port=5432 host=localhost password=senhadobanco user=seuusuario");
                if(!conn.is_open()) {
                    res.code = 400;
                    res.body = R"({"erro": "Erro ao abrir banco de dados."})";
                    std::cerr << "Erro ao abrir banco de dados: " << conn.dbname() << '\n';
                    return res;
                }

                auto body = nlohmann::json::parse(req.body);
                std::string documento = body.value("documento", std::string());

                if(documento.empty()) {
                    res.code = 400;
                    res.body = R"({"erro": "Campo documento obrigatorio."})";
                    return res;
                }

                pqxx::work txn(conn);
                //faz o select basico, basicamente um select normal
                pqxx::result slec = txn.exec("SELECT do banco de dados...");

                nlohmann::json result = nlohmann::json::array();
                for(const auto& row : slec) {
                    //adicona as rows e coluns a variavel "result" para ser retornada no "res"
                    result.push_back({
                        //suas rows e coluns precisan ser add aqui! ex.: {"id", row["id"].as<int>()}
                        });
                    }

                txn.commit();
                res.code = 200;
                res.set_header("Content-Type", "application/json");
                res.body = result.dump();
            }catch(const std::exception& e) {
                res.code = 400;
                std::cerr << e.what() << '\n';
            }

                return res;
        });

        app.port(8080).multithreaded().run();
    return 0;
}

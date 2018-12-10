Cidade *inicializa(Cidade *cidade) {
    
    cidade = cadastrarCidade(cidade, "Passo Fundo");
    cidade = cadastrarCidade(cidade, "POA");
    cidade = cadastrarCidade(cidade, "Pelotas");
    cidade = cadastrarCidade(cidade, "Bage");
    cidade = cadastrarCidade(cidade, "Sao Gabriel");
    cidade = cadastrarCidade(cidade, "Alegrete");
    cidade = cadastrarCidade(cidade, "Sao Borja");
    cidade = cadastrarCidade(cidade, "Santiago");
    cidade = cadastrarCidade(cidade, "Cruz Alta");
    cidade = cadastrarCidade(cidade, "SM");  

    // chamo essa funcao pois ela inverte os parametros para criar o caminho de ida e volta
    cidade = cadastrarRotaIniciais("Passo Fundo", "POA", 289, cidade);
    cidade = cadastrarRotaIniciais("POA", "Pelotas", 261, cidade);
    cidade = cadastrarRotaIniciais("Pelotas", "Bage", 189, cidade);
    cidade = cadastrarRotaIniciais("Bage", "Sao Gabriel", 268, cidade);
    cidade = cadastrarRotaIniciais("Sao Gabriel", "Alegrete", 204, cidade);
    cidade = cadastrarRotaIniciais("Alegrete", "Sao Borja", 315, cidade);
    cidade = cadastrarRotaIniciais("Sao Borja", "Santiago", 141, cidade);
    cidade = cadastrarRotaIniciais("Santiago", "Cruz Alta", 242, cidade);
    cidade = cadastrarRotaIniciais("Cruz Alta", "Passo Fundo", 149, cidade);
    cidade = cadastrarRotaIniciais("Cruz Alta", "SM", 134, cidade);
    cidade = cadastrarRotaIniciais("SM", "Santiago", 152, cidade);
    cidade = cadastrarRotaIniciais("SM", "Alegrete", 258, cidade);
    cidade = cadastrarRotaIniciais("SM", "Sao Gabriel", 182, cidade);
    cidade = cadastrarRotaIniciais("SM", "Bage", 239, cidade);
    cidade = cadastrarRotaIniciais("SM", "POA", 291, cidade);
    cidade = cadastrarRotaIniciais("POA", "Bage", 377, cidade);

   return cidade;
}
#include <cgreen/cgreen.h>
#include "main.c"

Describe(Cgreen);
BeforeEach(Cgreen) {}
AfterEach(Cgreen) {}

Ensure(Cgreen, passes_this_test) {
    assert_that(1 == 1);
}

Ensure(Cgreen, fails_this_test) {
    assert_that(0 == 1);
}

int main(int argc, char **argv) {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, Cgreen, passes_this_test);
    add_test_with_context(suite, Cgreen, fails_this_test);
    assert_that(imprimeLista, true);
    assert_that(locacao(filme *listaFilme), true);
    assert_that(imprimeLista(filme *listaFilmes, char *chave), true);
    assert_that(entrega_filmes(filme *listaFilmes, char *chave), true);
    assert_that(busca_titulo(filme *listaFilmes, char *chave), true);
    assert_that(busca_codigo(filme *listaFilmes, int chaveInt), true);
    assert_that(busca_ano(filme *listaFilmes, int chaveInt), true);
    assert_that(busca_quantidade(filme *listaFilmes, int chaveInt), true);
    assert_that(busca_genero(filme *listaFilmes, char *chave), true);
    assert_that(impressao(), true);
    assert_that(relatorios(), true);
    assert_that(acervo_completo(), true);

    return run_test_suite(suite, create_text_reporter());
}

/*
 * Copyright (C) 2024 - 2025, Stephan Mueller <smueller@chronox.de>
 *
 * License: see LICENSE file in root directory
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ALL OF
 * WHICH ARE HEREBY DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF NOT ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#include "compare.h"
#include "cpufeatures.h"
#include "lc_sphincs.h"
#include "lc_status.h"
#include "small_stack_support.h"
#include "ret_checkers.h"
#include "visibility.h"

#ifdef LC_SPHINCS_SHAKE_256s_ENABLED
static const unsigned int lc_sphincs_type = LC_SPHINCS_SHAKE_256s;
#elif defined(LC_SPHINCS_SHAKE_256f_ENABLED)
static const unsigned int lc_sphincs_type = LC_SPHINCS_SHAKE_256f;
#elif defined(LC_SPHINCS_SHAKE_192s_ENABLED)
static const unsigned int lc_sphincs_type = LC_SPHINCS_SHAKE_192s;
#elif defined(LC_SPHINCS_SHAKE_192f_ENABLED)
static const unsigned int lc_sphincs_type = LC_SPHINCS_SHAKE_192f;
#elif defined(LC_SPHINCS_SHAKE_128s_ENABLED)
static const unsigned int lc_sphincs_type = LC_SPHINCS_SHAKE_128s;
#elif defined(LC_SPHINCS_SHAKE_128f_ENABLED)
static const unsigned int lc_sphincs_type = LC_SPHINCS_SHAKE_128f;
#endif

static int lc_sphincs_fips_keygen_test(void)
{
	struct workspace {
		struct lc_sphincs_pk pk;
		struct lc_sphincs_sk sk;
	};
	int ret;
	LC_DECLARE_MEM(ws, struct workspace, sizeof(uint64_t));

	/* Rerun power up integrity test */
	lc_fips_integrity_checker();

	CKINT(lc_sphincs_keypair(&ws->pk, &ws->sk, lc_seeded_rng,
				 lc_sphincs_type));

out:
	LC_RELEASE_MEM(ws);
	return ret;
}

LC_TEST_FUNC(int, main, int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	return lc_sphincs_fips_keygen_test();
}

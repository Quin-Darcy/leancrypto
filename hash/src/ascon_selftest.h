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

#ifndef ASCON_SELFTEST_H
#define ASCON_SELFTEST_H

#include "lc_ascon_hash.h"

#ifdef __cplusplus
extern "C" {
#endif

void ascon_256_selftest_common(const struct lc_hash *ascon, int *tested,
			       const char *impl);
void ascon_128a_selftest_common(const struct lc_hash *ascon, int *tested,
				const char *impl);
void ascon_xof_selftest_common(const struct lc_hash *ascon, int *tested,
			       const char *impl);
void ascon_cxof_selftest_common(const struct lc_hash *ascon, int *tested,
				const char *impl);

#ifdef __cplusplus
}
#endif

#endif /* ASCON_SELFTEST_H */

/**
* \file
* \ingroup qf
* \brief QActive_unsubscribe() definition.
* \cond
******************************************************************************
* Product: QF/C
* Last updated for version 5.3.0
* Last updated on  2014-02-15
*
*                    Q u a n t u m     L e a P s
*                    ---------------------------
*                    innovating embedded systems
*
* Copyright (C) Quantum Leaps, www.state-machine.com.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Alternatively, this program may be distributed and modified under the
* terms of Quantum Leaps commercial licenses, which expressly supersede
* the GNU General Public License and are specifically designed for
* licensees interested in retaining the proprietary status of their code.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
* Contact information:
* Web:   www.state-machine.com
* Email: info@state-machine.com
******************************************************************************
* \endcond
*/
#define QP_IMPL           /* this is QP implementation */
#include "qf_port.h"      /* QF port */
#include "qf_pkg.h"
#include "qassert.h"
#ifdef Q_SPY              /* QS software tracing enabled? */
    #include "qs_port.h"  /* include QS port */
#else
    #include "qs_dummy.h" /* disable the QS software tracing */
#endif /* Q_SPY */

Q_DEFINE_THIS_MODULE("qa_usub")

/****************************************************************************/
/**
* \description
* This function is part of the Publish-Subscribe event delivery mechanism
* available in QF. Un-subscribing from an event means that the framework
* will stop posting published events with a given signal \a sig to the
* event queue of the active object \a me.
*
* \note Due to the latency of event queues, an active object should NOT
* assume that a given signal \a sig will never be dispatched to the
* state machine of the active object after un-subscribing from that signal.
* The event might be already in the queue, or just about to be posted
* and the un-subscribe operation will not flush such events.
*
* \note Un-subscribing from a signal that has never been subscribed in the
* first place is considered an error and QF will raise an assertion.
*
* \sa QF_publish_(), QActive_subscribe(), and QActive_unsubscribeAll()
*/
void QActive_unsubscribe(QActive const * const me, enum_t const sig) {
    uint_fast8_t p = me->prio;
    uint_fast8_t i = (uint_fast8_t)Q_ROM_BYTE(QF_div8Lkup[p]);
    QF_CRIT_STAT_

    /** \pre the singal and the prioriy must be in ragne, the AO must also
    * be registered with the framework
    */
    Q_REQUIRE_ID(100, ((enum_t)Q_USER_SIG <= sig)
              && (sig < QF_maxSignal_)
              && ((uint_fast8_t)0 < p) && (p <= (uint_fast8_t)QF_MAX_ACTIVE)
              && (QF_active_[p] == me));

    QF_CRIT_ENTRY_();

    QS_BEGIN_NOCRIT_(QS_QF_ACTIVE_UNSUBSCRIBE, QS_priv_.aoObjFilter, me)
        QS_TIME_();             /* timestamp */
        QS_SIG_((QSignal)sig);  /* the signal of this event */
        QS_OBJ_(me);            /* this active object */
    QS_END_NOCRIT_()

    /* clear priority bit */
    QF_PTR_AT_(QF_subscrList_, sig).bits[i] &= Q_ROM_BYTE(QF_invPwr2Lkup[p]);
    QF_CRIT_EXIT_();
}

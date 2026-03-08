#include <sys/event.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

int
main(void)
{
    int kq;
    struct kevent kev;
    struct kevent ev;

    const char *message = "Hello World";

    /* Create kqueue */
    kq = kqueue();
    if (kq < 0) return 1;

    /* Register USER event notifier */
    EV_SET(
        &kev,
        1,                      /* ident (user-defined ID) */
        EVFILT_USER,            /* filter */
        EV_ADD | EV_CLEAR,      /* flags */
        NOTE_FFNOP,             /* fflags */
        0,
        (void *)message   /* udata */
    );

    if (kevent(kq, &kev, 1, NULL, 0, NULL) < 0) return 1;

    /* Trigger the notifier */
    EV_SET(
        &kev,
        1,                      /* same ident */
        EVFILT_USER,
        0,
        NOTE_TRIGGER,           /* trigger event */
        0,
        (void *)message
    );

    kevent(kq, &kev, 1, NULL, 0, NULL);

    /* Wait for event */
    if (kevent(kq, NULL, 0, &ev, 1, NULL) > 0) {
        printf("kqueue print: %s\n", (char *)ev.udata);
        if (ev.filter == EVFILT_USER) printf("Event Trigger\n");
    }

    close(kq);
    return 0;
}

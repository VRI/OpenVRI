// C++ Headers
#include <time.h>
#include <errno.h>
#include <sys/timerfd.h>

// ROS Headers
#include <ros/console.h>

// Specific Headers
#include <process_name/motiontimer.h>

const double SECONDTONANO = 1000000000;

MotionTimer::MotionTimer(double rate)

#ifdef MONITOR
 : m_monitor("timerfd")
#endif
{
	m_timerfd = timerfd_create(CLOCK_MONOTONIC, 0);

	itimerspec timespc;
	memset(&timespc, 0, sizeof(timespc));

	timespc.it_interval.tv_sec = 0;
	timespc.it_interval.tv_nsec = (long)(rate * SECONDTONANO);
	timespc.it_value.tv_sec = 0;
	timespc.it_value.tv_nsec = 1;

	if(timerfd_settime(m_timerfd, 0, &timespc, 0) != 0)
	{
		perror("timerfd_settime");
		ROS_ERROR("Could not setup timer");
		abort();
	}
}

MotionTimer::~MotionTimer()
{
	close(m_timerfd);
}

long unsigned int MotionTimer::sleep()
{
#ifdef MONITOR
	m_monitor.setBeginningTimestamp(ros::Time::now());
#endif
	int result;
	uint64_t expirations;

	do
		result = read(m_timerfd, &expirations, sizeof(expirations));
	while (result == EINTR);

	if (result < 0)
	{
		perror("read");
		ROS_ERROR("Could not read from timer");
		return -1;
	}

#ifdef MONITOR
	m_monitor.setEndingTimestamp(ros::Time::now());
#endif

	return expirations;
}

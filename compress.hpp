namespace itertools
{

    template <typename T1, typename T2>
    class compress
    {
    private:
        T1 m_container;
        T2 m_bool_container;

    public:
        /* the iterator */
        class iterator
        {
        public:
            iterator(typename T1::iterator from, typename T1::iterator to, typename T2::iterator bool_itr) : m_begin(from),
                                                                                                             m_end(to),
                                                                                                             m_bool_itr(bool_itr),
                                                                                                             m_current_true(*from) {}
            iterator(const iterator &other) : m_begin(other.m_begin),
                                              m_end(other.m_end),
                                              m_bool_itr(other.m_bool_itr),
                                              m_current_true(other.m_current_true) {}
            decltype(*(m_container.begin())) operator*() const
            {
                return m_current_true;
            }
            iterator &operator++()
            {
                return *this;
            }
            bool operator!=(const iterator &other) const
            {
                return false;
            }

        private:
            typename T1::iterator m_begin;
            typename T1::iterator m_end;
            typename T2::iterator m_bool_itr;
            decltype(*(m_container.begin())) m_current_true;
        };

    public:
        /* compress methods - decleration */
        compress(T1 container, T2 bool_container) : m_container(container),
                                                    m_bool_container(bool_container) {}
        iterator begin()
        {
            return iterator{m_container.begin(), m_container.end(), m_bool_container.begin()};
        }
        iterator end()
        {
            return iterator{m_container.end(), m_container.end(), m_bool_container.end()};
        }
    };
} 